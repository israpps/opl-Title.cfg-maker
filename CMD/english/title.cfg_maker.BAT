@echo off
cd /d %~dp0
set BatchDir=%CD%
:QUICKMODE
FOR %%x in (%*) do (
copy %%x %BatchDir% >nul
)
::
mode 120,30
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================

%q%
echo IMPORTANT        It only works on OPL Beta 1277 IFCARO or newer
%q%
timeout 5
cls
echo ========================================================================================================================
title === Title.cfg Maker ===
echo This batch file will prepare every .ELF file present in this directory (or ELF files opened with the .BAT)
echo to be launched by OPL beta
echo                                                                                                                       -
echo Made by El_Isra
echo https://github.com/israpps/opl-Title.cfg-maker
echo it's recomended to place this batch file in the APPS folder of OPL 
echo ========================================================================================================================
timeout 10
:GET_ELF
echo checking for ELF files...
dir /b /o:n *.ELF >ISR.ETL
set dea=true
::LOOP###############################################################################################################
for /f "delims=" %%a in (ISR.ETL) do (
echo 																															-
echo procesing [%%a]
IF NOT EXIST "%CD%\%%~na\title.cfg" (
																	MD "%%~na"
																	Cd "%%~na"
																		(
																		Echo title=%%~na
																		Echo boot=%%a
																		)>title.cfg
																	Cd..
																	Move "%%a" "%CD%\%%~na\%%a"
															) ELSE (
															echo error.
															echo an app called [%%a] already exists
															)
)
::LOOP###############################################################################################################
echo .
echo .
echo .
echo .
echo ========================================================================================================================
echo Execution ended.
echo erasing cache
echo ========================================================================================================================

del ISR.ETL
pause
pause
