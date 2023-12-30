#include <iostream>
#include <format>
#include <exception>
#include <regex>
#include <random>
#include <fstream>

#ifndef STRATEGY_STRATEGY_H
#define STRATEGY_STRATEGY_H

namespace strategy {
    using random = std::mt19937;

    class read_format_error : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    class istream : public std::istream {
        using std::istream::istream;
    public:
        int readInt();
        int readInt(int l, int r);
        long long readLongLong();
        long long readLongLong(long long l, long long r);
        std::string readWord();
        std::string readWord(const std::string& expression);
        void readSpace();
        void readEOL();
        void readEOF();
    };

    class ostream : public std::ostream {
        using std::ostream::ostream;
    };

    class ifstream : public istream {
    public:
        ifstream(const std::string& path) : istream(std::fstream(path).rdbuf()) {}
        ifstream(const char* path) : istream(std::fstream(path).rdbuf()) {}
    };

    class ofstream : public ostream {
    public:
        ofstream(const std::string& path) : ostream(std::fstream(path).rdbuf()) {}
        ofstream(const char* path) : ostream(std::fstream(path).rdbuf()) {}
    };

    struct CheckerJudgement {
        std::string status;
        double points;
    };

    int checker_main(int argc, char* argv[], CheckerJudgement (*check)(istream& input, istream& output, istream& answer, ostream& judgement));

    class Checker {
    protected:
        istream input, output, answer;
        ostream judgement;
        virtual CheckerJudgement check() = 0;
    public:
        int main(int argc, char* argv[]);
        virtual ~Checker() = default;
    };
}

#endif //STRATEGY_STRATEGY_H
