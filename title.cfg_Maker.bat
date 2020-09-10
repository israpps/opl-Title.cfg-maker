@echo off
mode 200,40
::Checkeo LANG ###NO FUNCIONA###
IF EXIST LangVarload.BAT (
	CALL LangVarload.BAT
  goto brk
	)ELSE(
	color 0a
	echo missing LangVarload
	echo Falta LangVarload
	)
:brk
set q=echo ------------------------------------------------------------------------------------------------------------------------
set w=echo ========================================================================================================================

%q%
echo %lng_warning%
%q%
timeout 5
cls
echo ========================================================================================================================
title creador de title.cfg masivo
echo %lng0%
echo %lng1%
echo %lng2%
echo                                                                                                                       -
echo %lng3%
echo https://github.com/israpps/opl-Title.cfg-maker
echo %lng4%
echo ========================================================================================================================
timeout 10
:GET_ELF
::Generar listado temporal de archivo ELF
echo analizando directorio...
IF EXIST *.ELF  (
dir /b /o:n *.ELF >ISR.ETL
  ) ELSE (
  cls
  color 0a
  echo %lng5%
  )
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
