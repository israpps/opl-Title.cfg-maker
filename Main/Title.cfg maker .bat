@echo off
:GetLang
If exist LANG.BAT (
CALL LANG.BAT
GOTO Begin
) ELSE (
Echo Lang.bat missing
Echo lang.bat faltante
Pause
Exit
)
:Begin
@title title.cfg maker v1.0
:Ask
Set /p TITLE=%lng_title%
Echo %lng_boot_lang1%
Set /p BOOT=%lng_boot_lang2%
:#Makefolder
MD %title%
Cd %title%
:#Makefile
Echo title=%TITLE%>title.cfg
Echo boot=%BOOT%>>title.cfg
Cd..
:MoveELF
Move %boot% "%CD%\%title%\%boot%"
:End
Pause
