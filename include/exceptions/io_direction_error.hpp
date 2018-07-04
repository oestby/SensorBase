#ifndef IO_DIRECTION_ERROR_HPP
#define IO_DIRECTION_ERROR_HPP

#include <stdexcept>
namespace tools {
///Thrown if you try to write to an input configured pin.
class IoDirectionError : public std::logic_error {
    public:
        IoDirectionError() : std::logic_error("Wrong IO direction") {}
};
}

#endif //IO_DIRECTION_ERROR_HPP

