# ReDeathmatch

<h1 align="center">
    <a href="https://github.com/wopox1337/ReDeathmatch">
        <picture>
            <source
                media="(prefers-color-scheme: dark)"
                srcset="https://user-images.githubusercontent.com/25423296/163456776-7f95b81a-f1ed-45f7-b7ab-8fa810d529fa.png"
            >
            <source
                media="(prefers-color-scheme: light)"
                srcset="https://user-images.githubusercontent.com/25423296/163456779-a8556205-d0a5-45e2-ac17-42d089e3c3f8.png"
            >
            <img
                alt=""
                src="https://user-images.githubusercontent.com/25423296/163456779-a8556205-d0a5-45e2-ac17-42d089e3c3f8.png"
            >
        </picture>
    </a>
</h1>

<p align="center">
    AMXModX plugins to provide Deathmatch gameplay in Counter-Strike 1.6 optimized to work with ReGameDLL:CS.
</p>

<p align="center">
    <a href="https://github.com/wopox1337/ReDeathmatch/releases/latest">
        <img
            src="https://img.shields.io/github/downloads/wopox1337/ReDeathmatch/total?label=Download%40latest&style=flat-square&logo=github&logoColor=white"
            alt="Build status"
        >
    </a>
    <a href="https://github.com/wopox1337/ReDeathmatch/actions">
        <img
            src="https://img.shields.io/github/workflow/status/wopox1337/ReDeathmatch/CI/master?style=flat-square&logo=github&logoColor=white"
            alt="Build status"
        >
    </a>
    <a href="https://github.com/wopox1337/ReDeathmatch/releases">
        <img
            src="https://img.shields.io/github/v/release/wopox1337/ReDeathmatch?include_prereleases&style=flat-square&logo=github&logoColor=white"
            alt="Release"
        >
    </a>
    <a href="https://www.amxmodx.org/downloads-new.php">
        <img
            src="https://img.shields.io/badge/AMXModX-%3E%3D1.9.0-blue?style=flat-square"
            alt="AMXModX dependency"
        >
        </a>
</p>

## About
- TODO

## Features
- TODO

## Requirements
- HLDS installed;
- [ReGameDLL](https://github.com/s1lentq/ReGameDLL_CS) installed;
- Installed AMXModX ([`v1.9`](https://www.amxmodx.org/downloads-new.php) or [`v1.10`](https://www.amxmodx.org/downloads-new.php?branch=master));
- Installed [ReAPI](https://github.com/s1lentq/reapi) module; 
      
## Installation
- [Download the latest](https://github.com/wopox1337/ReDeathmatch/releases/latest) stable version from the release section.
- Extract the `cstrike` folder to the root folder of the HLDS server;
- Make sure that all plugins are running and in the correct order, using the `amxx list` command.

## Updating
- Put new plugins and lang-files (`plugins/*.amxx` & `data/lang/*.txt`) into `amxmodx/` folder on the HLDS server;
- Restart the server (command `restart` or change the map);
- Make sure that the versions of the plugins are up to date with the command `amxx list`.

## Downloads
- [Release builds](https://github.com/wopox1337/ReDeathmatch/releases)
- [Dev builds](https://github.com/wopox1337/ReDeathmatch/actions/workflows/build.yml)
