@echo off
mode 200,40
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================

%q%
echo IMPORTANTE# solo funciona con opl beta superior a OPL 1460_DB o OPL 1277 IFCARO
%q%
timeout 5
cls
echo ========================================================================================================================
title creador de title.cfg masivo
echo este archivo por lotes creara un archivo title.cfg para cada archivo ELF presente en esta carpeta y movera los ELF a la
echo carpeta que le corresponda
echo el nombre del archivo no debe contener puntos (excepto la extension)
echo                                                                                                                       -
echo creado por El_Isra
echo https://github.com/israpps/opl-Title.cfg-maker
echo se recomienda dejar este archivo en la carpeta APPS del opl si juega por USB o SMB para facilitar el proceso
echo ========================================================================================================================
timeout 10
:GET_ELF
echo checking for ELF files...
dir /b /o:n *.ELF >ISR.ETL
set dea=true
::LOOP###############################################################################################################
for /f "delims=" %%a in (ISR.ETL) do (
:: crear carpeta y entrar en ella
MD "%%~na"
Cd "%%~na"
::crear title.cfg y salir de la carpeta
Echo title=%%~na>title.cfg
Echo boot=%%a.ELF>>title.cfg
Cd..
::meter ELF dentro de la carpeta
Move "%%a" "%CD%\%%~na\%%a"
:End
del ISR.ETL
)
::LOOP###############################################################################################################
::delete temp
del ISR.ETL
