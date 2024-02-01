#ifndef STRATEGY_ERRORS_H
#define STRATEGY_ERRORS_H

#include <stdexcept>

namespace strategy {
    class read_format_error : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}

#endif //STRATEGY_ERRORS_H
