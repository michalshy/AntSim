#include <gtest/gtest.h>
#include "../src/Logic/Timer.hpp"

sf::Clock Timer::clk;
sf::Time Timer::dt;

// Demonstrate some basic assertions.
TEST(TimerTest, BasicComparation) {
      Timer::Restart();
      int dt = Timer::GetDt().asSeconds();
      EXPECT_LE(dt, 1);
}