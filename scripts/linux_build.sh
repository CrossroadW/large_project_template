#cmake -S .. -B build -G Ninja -D ABC_DEFINE=VALUE
cmake -S .. -B ../build -G Ninja -DCMAKE_BUILD_TYPE=Debug &&
cmake --build ../build -j 8
