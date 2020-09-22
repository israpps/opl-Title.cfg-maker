@echo off
mode 120,30
IF EXIST LangVarload.BAT (
   CALL LangVarload.BAT
) ELSE (
color 0c
Echo NO LANG
echo LangVarload.BAT IS MISSING
TIMEOUT 10 /NOBREAK
exit
)
::################################## DETECT OPL FOLDER
SET /A z=0
SET BATHome=%CD%
cd..
IF EXIST "%CD%\CHT" SET /A z=z+1
IF EXIST "%CD%\APPS" SET /A z=z+1
IF EXIST "%CD%\CFG" SET /A z=z+1
IF EXIST "%CD%\ART" SET /A z=z+1
IF EXIST "%CD%\CD" SET /A z=z+1
IF EXIST "%CD%\DVD" SET /A z=z+1
IF "%BATHome%"=="%CD%\APPS" SET /A z=z+1
cd %BATHome%
IF %z% GEQ "7" SET installlang=True
IF %installlang%==True (
ATTRIB LangVarload.BAT +h
)
::##################################
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================
%q%
echo %lang1%
%q%
timeout 7
cls
echo ========================================================================================================================
title %title-lang%
echo %lang2%
echo %lang3%
echo                                                                                                                       -
echo %lang4%
echo https://github.com/israpps/opl-Title.cfg-maker
echo %lang5%
echo ========================================================================================================================
timeout 11
CLS
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
Echo boot=%%a>>title.cfg
Cd..
::meter ELF dentro de la carpeta
Move "%%a" "%CD%\%%~na\%%a"
TIMEOUT 2
)
::LOOP###############################################################################################################
::delete temp
del ISR.ETL
IF %installlang%==True RENAME "%CD%\title.cfg_Maker.bat" "__title.cfg_Maker.bat"
