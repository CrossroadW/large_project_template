cmake -S .. -B ../build -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug &&
cmake --build ../build -j 8 --config Debug
