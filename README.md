# 对于一个大型 C++ 项目，我们需要：

- 支持单独编译：项目既可以独立编译，也可以作为其他项目的子模块（通过 add_subdirectory）。
- 支持多个库：包括静态库和动态库，可以在项目中自由组合使用。
- 支持测试：使用 GoogleTest 和 GoogleBenchmark 进行单元测试和性能测试。
- 支持可选功能：所有编译选项都可以通过 option() 控制，并在 CMakeLists.txt 开头定义默认值。
- 支持扩展性：允许额外目标的添加，并预留注释位置以便扩展。
- 支持多平台和工具链：可以适配不同的编译器、平台，并支持交叉编译。
- 支持模块化设计：每个模块（库、可执行文件、测试）都有单独的 CMakeLists.txt，使得整个项目易于维护和扩展。


```shell

/MyProject
│── CMakeLists.txt         # 顶层 CMake 入口
│── cmake
│   ├── linux_x64.cmake         # 编译工具链文件（交叉编译）
│   └── options.cmake      # 选项控制文件
│── include                # 头文件
│   ├── myproject          # 主要库的头文件
│   └── module_a           # 其他模块的头文件
│── src                    # 源代码
│   ├── main.cpp           # 主程序入口
│   ├── myproject          # 主要库
│   ├── module_a           # 模块 A
│   ├── module_b           # 模块 B
│   └── CMakeLists.txt     # 组织多个模块
│── tests                  # 测试代码
│   ├── CMakeLists.txt     # 测试组织
│   ├── test_main.cpp      # GoogleTest 入口
│   ├── test_module_a.cpp  # 测试 A 模块
│   ├── test_module_b.cpp  # 测试 B 模块
│   └── benchmarks         # GoogleBenchmark 测试
│── apps                   # 可执行应用程序
│   ├── app1
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   └── app2
│       ├── main.cpp
│       ├── CMakeLists.txt
│── third_party            # 第三方库（可选）
│── build                  # CMake 生成目录（推荐 out-of-source 编译）
│── scripts                # 构建/运行/测试脚本
└── README.md              # 项目说明

```