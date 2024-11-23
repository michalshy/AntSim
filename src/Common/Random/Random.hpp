#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include <random>
#include <type_traits>

template<typename T>
class Random {
    using ret_type = std::conditional_t<
        std::is_integral_v<T>,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>>;
    std::random_device dev;
    std::mt19937 rng;
    ret_type dis;
public:
    Random(T from, T to);
    const T Generate() { 
        return dis(rng);
    }
};

#endif //__RANDOM_HPP__

template <typename T>
inline Random<T>::Random(T from, T to)
{
    rng = std::mt19937(dev());
    dis = ret_type(from, to);
}
