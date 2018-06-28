#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <type_traits>

namespace tools {

//This template should only be available for arithmetic types 
template<typename T,
         typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string padNumberWithZeros(T number, int zeros) {
    std::string padded = "";
    for(int i = 0; i < zeros; ++i) {
        padded += "0";
    }
    padded += to_string(number);
    return padded;
}

} //namespace tools
#endif //TOOLS_HPP

