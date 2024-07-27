#ifndef GLOBALS_HPP
#define GLOBALS_HPP

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using s8 = int8_t;
using s16 = int16_t;
using s32 = int32_t;
using s64 = int64_t;

namespace MathConsts
{
    constexpr double PI = 3.14; 
}

namespace AntConsts
{
    constexpr u8 ANT_HEIGHT = 20;
    constexpr u8 ANT_WIDTH = 15;
}

namespace WindowParams
{
    constexpr u16 width = 1600;
    constexpr u16 height = 800;
}


#endif