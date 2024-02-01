#ifndef STRATEGY_GENERATOR_H
#define STRATEGY_GENERATOR_H

#include "fstream.h"
#include "random.h"

namespace strategy {
    class Generator {
    protected:
        ofstream output;

        virtual void generate(int count, char** arguments) = 0;
    public:
        int main(int argc, char* argv[]);
        virtual ~Generator() = default;
    };
}

#endif //STRATEGY_GENERATOR_H
