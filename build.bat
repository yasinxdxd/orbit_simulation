mkdir build
cd build
cmake -DCMAKE_GENERATOR_PLATFORM=x64 ..
cmake --build .
copy "..\lib\engine.dll" ".\Debug\"
Xcopy /E "..\resource\" ".\Debug\"
