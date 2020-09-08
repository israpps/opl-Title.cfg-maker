:GetLang
If exist LANG.BAT (
CALL LANG.BAT
) ELSE (
Echo Lang.bat missing
Echo lang.bat faltante
Pause
Exit
)
@echo off
@title title.cfg maker v1.0
:Ask
Set /p title=%lng_title%
Echo %lng_boot_lang1%
Set /p boot=%lng_boot_lang2%
:#Makefolder
MD %title%
Cd %title%
:#Makefile
Echo title=%title%>>title.cfg
Echo boot=%boot%>title.cfg
CD..
:MoveELF
move /Y %cd%%boot% %cd%%title%\%boot%
Echo %lng_end1%
:End
Pause
