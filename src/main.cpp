#include <iostream>
#include <module_a/MyLib.h>

int main() {
    MyLib lib;
    std::cout << "2 + 3 = " << lib.add(2, 3) << std::endl;
    return 0;
}