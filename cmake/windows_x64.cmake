set(CMAKE_SYSTEM_NAME Windows)

# set(CMAKE_SYSTEM_PROCESSOR AMD64)
set(CMAKE_C_COMPILER cl.exe)
set(CMAKE_CXX_COMPILER cl.exe)

# 添加编译选项，启用较高的警告级别，以捕获潜在的问题。
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")

# 添加预处理器定义 WIN32 和 WINDOWS。
# 这些定义通常用于在代码中进行条件编译，以便为 Windows 平台编写特定代码。
add_definitions(-DWIN32)
add_definitions(-DWINDOWS)

# 设置运行时库选项，使用多线程库。在 Debug 配置下使用多线程调试库
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")