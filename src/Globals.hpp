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

namespace AntHillConsts {
    constexpr u8 ANT_NUMBER = 40;
}

namespace AntConsts {
    constexpr u8 HEIGHT = 20;
    constexpr u8 WIDTH = 15;
}

namespace MathConsts {
    constexpr double PI = 3.14; 
}

namespace TimeConsts {
    constexpr double STEP = 0.1;
}

namespace WindowParams {
    constexpr u16 WIDTH = 1600;
    constexpr u16 HEIGHT = 800;
}


#endif //__GLOBALS_HPP__