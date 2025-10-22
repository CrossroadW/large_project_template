#include <gtest/gtest.h>
#include <gmock/gmock.h>


// **数据库接口**
class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual bool Connect(const std::string &url) = 0;

    virtual int GetUserAge(const std::string &username) = 0;
};

// **Mock 数据库**
class MockDatabase : public IDatabase {
public:
    MOCK_METHOD(bool, Connect, (const std::string& url), (override));
    MOCK_METHOD(int, GetUserAge, (const std::string& username), (override));
};

// **待测试的服务**
class UserService {
    IDatabase &db;

public:
    explicit UserService(IDatabase &database) : db(database) {
    }

    int FetchUserAge(const std::string &username) {
        if (!db.Connect("db://localhost")) {
            return -1; // 连接失败
        }
        return db.GetUserAge(username);
    }
};

// **测试 UserService**
TEST(UserServiceTest, FetchUserAgeTest) {
    MockDatabase mockDb; // 创建 Mock 对象
    UserService service(mockDb);

    // 设定预期行为
    EXPECT_CALL(mockDb, Connect).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockDb, GetUserAge("Alice")).WillOnce(::testing::Return(30));

    // 运行测试
    EXPECT_EQ(service.FetchUserAge("Alice"), 30);
}

class MockDatabase2 : public IDatabase {
public:
    MOCK_METHOD(bool, Connect, (const std::string& username), (override));
    MOCK_METHOD(int, GetUserAge, (const std::string& username), (override));
};

TEST(DatabaseTest, ConnectCalledOnce) {
    MockDatabase2 mockDb;
    EXPECT_CALL(mockDb, Connect).Times(::testing::AtLeast(2));

    mockDb.Connect("hello");
    mockDb.Connect("hello");
}
