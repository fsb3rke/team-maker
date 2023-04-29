//
// Created by berke on 4/30/2023.
//

#ifndef TEAM_MAKER_MARANDOM_H
#define TEAM_MAKER_MARANDOM_H

#include <iostream>
#include <random>
#include <type_traits>

inline std::mt19937& generator() {
    static thread_local std::mt19937 gen(std::random_device{}());
    return gen;
}

template<typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T my_rand(T min, T max) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(generator());
}

template<typename T, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
T my_rand(T min, T max) {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(generator());
}

#endif //TEAM_MAKER_MARANDOM_H
