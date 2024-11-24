#ifndef __GLOBALS_HPP__
#define __GLOBALS_HPP__

#include <cstdint>
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using s8 = int8_t;
using s16 = int16_t;
using s32 = int32_t;
using s64 = int64_t;

namespace ANTHILL {
    constexpr u8 ANT_NUMBER = 40;
}

namespace ANT {
    constexpr float SPEED = 30.0f;
    constexpr u8 HEIGHT = 5;
    constexpr u8 WIDTH = 3;
}

namespace MATH {
    constexpr double PI = 3.14; 
}

namespace TIME {
    constexpr double STEP = 0.1;
}

namespace WINDOW {
    constexpr u16 WIDTH = 1600;
    constexpr u16 HEIGHT = 800;

    constexpr s16 X_ZERO = -1 * (WIDTH/2);
    constexpr s16 Y_ZERO = -1 * (HEIGHT/2);
    constexpr s16 X_END = (WIDTH/2);
    constexpr s16 Y_END = (HEIGHT/2);

    constexpr u8 BOUND_THICKNESS = 5;
}


#endif //__GLOBALS_HPP__