#include <iostream>
// #include <module_a/MyLib.h>
#include <fstream>
#include <filesystem>
int main() {
    // MyLib lib;
    // std::cout << "2 + 3 = " << lib.add(2, 3) << std::endl;

    std::ifstream ifs("../CMakeLists.txt");
    if (!ifs.is_open()) {
        std::cout << "open failed\n";
    }
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    std::cout << content;

    return 0;
}
