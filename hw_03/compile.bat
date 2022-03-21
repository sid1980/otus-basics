del /s /q .\build\*
rmdir /s /q .\build\
mkdir .\build\

cd .\build\
cmake ..
cmake --build . --config Release 

Xcopy .\src\Release ..\Release /E/H/C/I

..\Release\game.exe



PAUSE >nul