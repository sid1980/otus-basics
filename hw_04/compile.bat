del /s /q .\build\*
rmdir /s /q .\build\
mkdir .\build\

cd .\build\
cmake ..
cmake --build . --config Release 


PAUSE >nul