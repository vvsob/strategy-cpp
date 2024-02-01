#include "checker.h"

namespace strategy {
    int Checker::main(int argc, char **argv) {
        if (argc != 5) {
            return 1;
        }
        input = ifstream(argv[1]);
        output = ifstream(argv[2]);
        answer = ifstream(argv[3]);
        judgement = ofstream(argv[4]);

        auto judgement_info = check();

        judgement << "status: " << judgement_info.status << "\n";
        if (!judgement_info.message.empty()) {
            judgement << "message: " << judgement_info.message << "\n";
        }
        judgement.close();
        return 0;
    }

    CheckerJudgement Checker::WA(std::string message) {
        return CheckerJudgement("WA", std::move(message));
    }

    CheckerJudgement Checker::OK(std::string message) {
        return CheckerJudgement("OK", std::move(message));
    }
}