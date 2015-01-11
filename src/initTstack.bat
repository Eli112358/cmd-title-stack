@echo off
set tStack=%~0\Title-Stack\%time::=-%.txt
copy /y nul %tStack% >nul
set "title=%~1"
title %title%
exit /b
