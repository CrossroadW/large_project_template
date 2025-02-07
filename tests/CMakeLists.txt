


add_executable(unit_tests test_main.cpp)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main module_a)

include(GoogleTest)
gtest_discover_tests(unit_tests)