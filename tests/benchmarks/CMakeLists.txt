cmake_minimum_required(VERSION 3.16)


add_executable(benchmarks benchmark_main.cpp benchmark_lib.cpp)
target_link_libraries(benchmarks PRIVATE benchmark_main module_a)