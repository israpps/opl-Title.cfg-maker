@echo off
mode 120,30
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================

%q%
echo %lang1%
%q%
timeout 5
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
