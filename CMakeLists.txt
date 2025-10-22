cmake_minimum_required(VERSION 3.20)

# 选项控制（默认值）
option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)
option(ENABLE_TESTS "Enable unit tests" ON)
option(ENABLE_BENCHMARKS "Enable benchmark tests" ON)
option(USE_THIRD_PARTY "Use external libraries instead of bundled ones" ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 载入 CMake 选项（独立存放在 cmake/options.cmake 里）
if (LINUX)
    include(cmake/linux_x64.cmake)
elseif (WIN32)
    #!todo
endif ()

project(large_project_template VERSION 1.0.0 LANGUAGES CXX)


add_subdirectory(src)

# 可选的测试和基准测试
if (ENABLE_TESTS)
    enable_testing()
    if (USE_THIRD_PARTY)
        add_subdirectory(third_party/googletest)
    else ()
        find_package(GTest REQUIRED)
    endif ()
    add_subdirectory(tests)
endif ()

if (ENABLE_BENCHMARKS)
    if (USE_THIRD_PARTY)
        add_subdirectory(third_party/benchmark)
    elseif()
        find_package(benchmark REQUIRED)
    endif ()

    add_subdirectory(tests/benchmarks)
endif ()



