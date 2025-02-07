#include <module_a/MyLib.h>
#include <gtest/gtest.h>

TEST(MyLibTest, AddFunction) {
    MyLib lib;
    EXPECT_EQ(lib.add(2, 3), 5);
    EXPECT_EQ(lib.add(-1, 1), 0);
}

int main(int argc, char **argv) {
    std::cout << "main func\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}