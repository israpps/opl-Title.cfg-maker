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
:End
del ISR.ETL
)
::LOOP###############################################################################################################
::delete temp
del ISR.ETL
