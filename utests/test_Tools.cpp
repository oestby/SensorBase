#include <tools/tools.hpp>
#include <gtest/gtest.h>

TEST(ToolTest, testPadding) {
    std::string expected = "0000000255";
    std::string result = tools::padNumberWithZeros(255, 10);
    ASSERT_EQ(expected, result);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
