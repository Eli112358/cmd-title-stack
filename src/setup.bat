@echo off
md Title-Stack
schtasks /create /sc onlogon /tn "Title-Stack" /tr "del %~0\Title-Stack\*"
exit
