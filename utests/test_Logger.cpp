#include <tools/logger.hpp>
#include <gtest/gtest.h>

using namespace tools;

class LoggerTest: public ::testing::Test {
    public:
        LoggerTest():
            logger("test.log")
    {

    }
    protected:
        Logger logger;
};

TEST_F(LoggerTest, infoTest) {
    logger.info("TESTING INFO");
}

TEST_F(LoggerTest, warnTest) {
    logger.warn("TESTING WARNING");
}

TEST_F(LoggerTest, errorTest) {
    logger.error("TESTING ERROR");
}

TEST_F(LoggerTest, debugTest) {
    logger.debug("TESTING DEBUG");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
