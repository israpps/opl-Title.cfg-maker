@echo off
mode 120,30
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
   MD "%%~na"
   Cd "%%~na"
     (
    Echo title=%%~na
    Echo boot=%%a
     )>title.cfg
   Cd..
   Move "%%a" "%CD%\%%~na\%%a"
)
::LOOP###############################################################################################################
::delete temp
del ISR.ETL
