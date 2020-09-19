@echo off
mode 200,40
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================

%q%
echo IMPORTANT# title.cfg only works with opl betas superior to 1460_DB or OPL 1277 Official beta
%q%
timeout 5
cls
echo ========================================================================================================================
title  title.cfg massive generator
echo this batch file will generate a title.cfg for every .ELF file in the directory, then It'll be 
echo moved into a sub-folder with the same name
echo the file name mustn't contain any extra dor (appart of extension)
echo                                                                                                                       -
echo made by El_Isra
echo https://github.com/israpps/opl-Title.cfg-maker
echo it's recommended to execute this on the opl APPS folder so you dont have to move the new folders
echo ========================================================================================================================
timeout 10
:GET_ELF
echo checking for ELF files...
dir /b /o:n *.ELF >ISR.ETL
set dea=true
::LOOP###############################################################################################################
for /f "delims=." %%a in (ISR.ETL) do (
:: crear carpeta y entrar en ella
MD "%%a"
Cd "%%a"
::crear title.cfg y salir de la carpeta
Echo title=%%a>title.cfg
Echo boot=%%a.ELF>>title.cfg
Cd..
::meter ELF dentro de la carpeta
Move "%%a.ELF" "%CD%\%%a\%boot%"
:End
del ISR.ETL
)
::LOOP###############################################################################################################
::delete temp
del ISR.ETL
