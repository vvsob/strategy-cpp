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
        std::string read();
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
    private:
        std::filebuf filebuf;
    public:
        ifstream();
        explicit ifstream(const std::string& path);
        explicit ifstream(const char* path);
        void close();
    };

    class ofstream : public ostream {
    private:
        std::filebuf filebuf;
    public:
        ofstream();
        explicit ofstream(const std::string& path);
        explicit ofstream(const char* path);
        void close();
    };

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

#endif //STRATEGY_STRATEGY_H
