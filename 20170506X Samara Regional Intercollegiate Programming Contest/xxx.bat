@echo off
:loop
srand.exe
C.exe
C.ture.exe
fc out1.txt out2.txt
if not errorlevel 1 goto loop
pause
end