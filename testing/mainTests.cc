#include <gtest/gtest.h>
#include "../src/Logic/Timer.hpp"

sf::Clock Timer::clk;
sf::Time Timer::dt;

// Demonstrate some basic assertions.
TEST(TimerTest, BasicComparation) {
      Timer::Restart();
      int dtSec = Timer::GetDt().asSeconds();
      EXPECT_LE(dtSec, 1);
      int dtMicro = Timer::GetDt().asMicroseconds();
      EXPECT_GE(dtMicro, 1);
}