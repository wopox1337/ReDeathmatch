static g_currentRoundModeIdx = -1
static redm_modes_switch[32]

RoundModes_Init() {
    RegisterHookChain(RG_RoundEnd, "RoundEnd", .post = false)
    RegisterHookChain(RG_CSGameRules_RestartRound, "CSGameRules_RestartRound", .post = false)
    RegisterHookChain(RG_CBasePlayer_OnSpawnEquip, "CBasePlayer_OnSpawnEquip", .post = false)

    bind_pcvar_string(
        create_cvar("redm_modes_switch", "sequentially"),
        redm_modes_switch,
        charsmax(redm_modes_switch)
    )
}

public RoundEnd(WinStatus: status, ScenarioEventEndRound: event, Float: tmDelay) {
    if (strcmp(redm_modes_switch, "disable") == 0)
        return

    new nextModeIdx = GetNextMode()
    if (nextModeIdx == -1)
        return

    // TODO:
    // SetHookChainArg(1, ATYPE_INTEGER, WINSTATUS_NONE)
    // SetHookChainArg(2, ATYPE_INTEGER, ROUND_TARGET_SAVED)

    new modeName[32]
    GetModeInfo(nextModeIdx, modeName, charsmax(modeName))

    client_print_color(0, print_team_red, "[Re:DM] Next mode is `^3%s^1`",
        modeName
    )

    g_currentRoundModeIdx = nextModeIdx
}

public CSGameRules_RestartRound() {
    if (g_currentRoundModeIdx == -1)
        return

    new modeName[32]
    if (!GetModeInfo(g_currentRoundModeIdx, modeName, charsmax(modeName)))
        return

    ApplyMode(g_currentRoundModeIdx)

    for (new p = 1; p <= MaxClients; p++) {
        EquipManager_PlayerResetEquip(p)
    }
}

public CBasePlayer_OnSpawnEquip(const player, bool: addDefault, bool: equipGame) {
    set_member(player, m_bNotKilled, false)
    rg_set_user_armor(player, 0, ARMOR_NONE)

    if (g_currentRoundModeIdx == -1)
        return

    new modeName[32]
    GetModeInfo(g_currentRoundModeIdx, modeName, charsmax(modeName))

    set_dhudmessage(
        .red = 200,
        .green = 200,
        .blue = 200,
        .y = 0.85,
        .holdtime = 4.0
    )

    SetGlobalTransTarget(player)

    new bool: isLang = (GetLangTransKey(modeName) != TransKey_Bad)

    show_dhudmessage(
        player,
        isLang ? "%l: %l" : "%l: %s",
        "CurrentMode",
        modeName
    )
}


static GetModeInfo(const index, name[], len) {
    if (!json_object_has_value(Config_GetCurrent(), "modes"))
        return false

    new JSON: objModes = json_object_get_value(Config_GetCurrent(), "modes")

    new count = json_object_get_count(objModes)
    if (!count) {
        return false
    }
    
    if (index < 0 || index >= count) {
        return false
    }

    json_object_get_name(objModes, index, name, len)

    json_free(objModes)

    return true
}

static GetNextMode() {
    if (!json_object_has_value(Config_GetCurrent(), "modes"))
        return -1

    new JSON: objModes = json_object_get_value(Config_GetCurrent(), "modes")

    new count = json_object_get_count(objModes)
    json_free(objModes)
    
    if (!count)
        return -1
    
    new currentIdx = g_currentRoundModeIdx
    
    if (strcmp(redm_modes_switch, "random") == 0) {
        currentIdx = random_num(0, count - 1)
    } else if (strcmp(redm_modes_switch, "sequentially") == 0) {
        ++currentIdx
        currentIdx %= count
    }
    
    return currentIdx
}


bool: ApplyMode(const index) {
    if (index < 0)
        return false

    ReloadConfig()

    if (!json_object_has_value(Config_GetCurrent(), "modes"))
        return false

    new JSON: objModes = json_object_get_value(Config_GetCurrent(), "modes")

    new count = json_object_get_count(objModes)
    if (!count)
        return false

    new JSON: objMode = json_object_get_value_at(objModes, index)
    if (json_object_has_value(objMode, "cvars")) {
        new JSON: objCvars = json_object_get_value(objMode, "cvars")

        CvarsHandler_LoadCvars(objCvars)

        json_free(objCvars)
    }

    json_free(objMode)
    json_free(objModes)

    return true
}

RoundModes_GetCurrentMode() {
    return g_currentRoundModeIdx    
}

RoundModes_ResetCurrentMode() {
    g_currentRoundModeIdx = -1    
}