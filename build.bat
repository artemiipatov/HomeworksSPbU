for /D %%s in (.\*) do ( 
cd %%s 
for /D %%s in (.\*) do (
cd %%s
MSBuild
if exist x64 (
    cd x64/Debug
    for /R %%I in (*.exe) do %%I 1
    if not errorlevel 0 (
        echo program did not pass tests
    ) else (
        echo program passed tests)
    cd ../..
)
cd ..)
cd ..)