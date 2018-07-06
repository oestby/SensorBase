#include <tools/time.hpp>
#include <gtest/gtest.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace tools;

class TimerTest: public ::testing::Test {
    public:
        TimerTest(): timer() {
            //Empty
        }
    protected:
        Time timer, timer_second;
};

TEST_F(TimerTest, startTimeTest) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Time timer_2;
    EXPECT_NE(timer.getStartTime(), timer_2.getStartTime());
    ASSERT_TRUE(timer.getRunTime() != 0);
}


TEST_F(TimerTest, currentTimeTest) {
    Time timer_2;
    ASSERT_EQ(timer.getCurrentTime(), timer_2.getCurrentTime());
}

TEST_F(TimerTest, stringTime) {
    EXPECT_EQ(timer.getCurrentTimeString(),
              timer_second.getCurrentTimeString());
    EXPECT_EQ(timer.getStartTimeString(),
              timer_second.getStartTimeString());
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


