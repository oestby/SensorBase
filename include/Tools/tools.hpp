#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <type_traits>

///Namespace containing helper functions and such.
namespace tools {

/**
This function is for padding numbers with zeros.

It is mostly for aesthetic purposes but also it will increas readability of logs and outputs.
This template should only be available for arithmetic types.
@param number This should only accept arithmetic types.
@param zeros How many zeros you would like there to be
@returns The fully padded string.
*/
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

