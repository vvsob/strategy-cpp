#include "strategy.h"

namespace strategy {
    int istream::readInt() {
        int result;
        *this >> result;
        return result;
    }

    int istream::readInt(int l, int r) {
        auto result = readInt();
        if (result < l || r < result) {
            auto message = std::format("readInt() value not in range. Expected: from {0} to {1}, got {2}", l, r, result);
            throw read_format_error(message);
        }
        return result;
    }

    long long istream::readLongLong() {
        int result;
        *this >> result;
        return result;
    }

    long long istream::readLongLong(long long l, long long r) {
        auto result = readLongLong();
        if (result < l || r < result) {
            auto message = std::format("readLongLong() value not in range. Expected: from {0} to {1}, got {2}", l, r, result);
            throw read_format_error(message);
        }
        return result;
    }

    void istream::readSpace() {
        char result = get();
        if (result != ' ') {
            auto message = std::format("readSpace() check failed. Got {0}", result);
            throw read_format_error(message);
        }
    }

    void istream::readEOL() {
        char result = get();
        if (result != '\n') {
            auto message = std::format("readEOL() check failed. Got {0}", result);
            throw read_format_error(message);
        }
    }

    void istream::readEOF() {
        char result = get();
        if (result != -1) {
            auto message = std::format("readEOF() check failed.");
            throw read_format_error(message);
        }
    }

    std::string istream::readWord() {
        std::string result;
        *this >> result;
        return result;
    }

    std::string istream::readWord(const std::string &expression) {
        auto word = readWord();
        if (!std::regex_match(word, std::regex(expression))) {
            auto message = std::format("readWord() regex check failed. Expression: {0}, got: {1}", expression, word);
            throw read_format_error(message);
        }
        return word;
    }

    int Checker::main(int argc, char **argv) {
        input = ifstream(argv[0]);
        output = ifstream(argv[1]);
        answer = ifstream(argv[2]);
        judgement = ofstream(argv[3]);

        auto judgement_info = check();

        judgement << "status: " << judgement_info.status << "\n";
        if (judgement_info.points != NAN) {
            judgement << "points: " << judgement_info.points << "\n";
        }
        return 0;
    }
}

