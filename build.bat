mkdir build
cd build
cmake -G "Visual Studio 16 2019" -DCMAKE_GENERATOR_PLATFORM=x64 ..
cmake --build .
copy "..\lib\engine.dll" ".\Debug\"
Xcopy /E "..\resource\" ".\Debug\"
