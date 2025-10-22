#include <module_a/MyLib.h>
#include <gtest/gtest.h>
#include <vector>
#include <queue>


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(MyLibTest, AddFunction) {
    MyLib lib;
    EXPECT_EQ(lib.add(2, 3), 5);
    EXPECT_EQ(lib.add(-1, 2), 1);
}

TEST(MyLibTest, CheckVectorsEqual) {
    std::vector<int> x = {1, 2, 3, 4, 5};
    std::vector<int> y = {1, 2, 3, 4, 5};

    // 检查两个向量的长度是否相等
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

    // 检查每个元素是否相等
    for (int i = 0; i < x.size(); ++i) {
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}

// 定义测试夹具类，继承自 ::testing::Test
class MyTestFixture : public ::testing::Test {
protected:
    int value;  // 共享的测试数据

    // 在每个测试用例执行前运行
    void SetUp() override {
        value = 42;
    }

    // 在每个测试用例执行后运行
    void TearDown() override {
        // 清理资源（如果需要）
    }
};

// 测试用例 1：检查 value 是否被正确初始化
TEST_F(MyTestFixture, ValueIsInitialized) {
    EXPECT_EQ(value, 42);
}

// 测试用例 2：修改 value 后的检查
TEST_F(MyTestFixture, ModifyValue) {
    value = 100;
    EXPECT_EQ(value, 100);
}
