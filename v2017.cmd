﻿@echo off
::环境配置
set MUDLIB="F:\Favorites\mudren-Lib-master\SZMUD"
set DRIVER="F:\Favorites\mudren-Lib-master\fluffos_2017\driver.exe"
set CONFIG="F:\Favorites\mudren-Lib-master\SZMUD\config.ini"
::运行游戏
:START
cd %MUDLIB%
%DRIVER% %CONFIG% %*
::goto START
pause