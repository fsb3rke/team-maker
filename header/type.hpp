//
// Created by berke on 4/30/2023.
//

#ifndef TEAM_MAKER_TYPE_HPP
#define TEAM_MAKER_TYPE_HPP

#include <string>
#include <typeinfo>

std::string demangle(const char* name);

template <class T>
std::string type(const T& t) {

    return demangle(typeid(t).name());
}

#endif //TEAM_MAKER_TYPE_HPP
