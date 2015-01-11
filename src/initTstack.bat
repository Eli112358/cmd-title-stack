@echo off
set tStack=%~0\Title-Stack\%time::=-%.txt
copy /y nul %tStack% >nul
exit /b
