#ifndef STRATEGY_CHECKER_H
#define STRATEGY_CHECKER_H

#include "fstream.h"

namespace strategy {
    struct CheckerJudgement {
        std::string status;
        std::string message;
    };

    class Checker {
    protected:
        ifstream input, output, answer;
        ofstream judgement;

        static CheckerJudgement WA(std::string message = "");
        static CheckerJudgement OK(std::string message = "");

        virtual CheckerJudgement check() = 0;
    public:
        int main(int argc, char* argv[]);
        virtual ~Checker() = default;
    };
}

#endif //STRATEGY_CHECKER_H
