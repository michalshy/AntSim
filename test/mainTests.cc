#include <gtest/gtest.h>
#include "../src/Logic/Timer.hpp"

// Demonstrate some basic assertions.
TEST(TimerTest, BasicComparation) {
      Timer t = Timer();
      int dtSec = Timer().GetDt().asSeconds();
      EXPECT_LE(dtSec, 1);
      int dtMicro = Timer().GetDt().asMicroseconds();
      EXPECT_GE(dtMicro, 1);
}