#include "strategy.h"
#include <iostream>
#include <format>
#include <regex>
#include <utility>

namespace strategy {
    std::string istream::read() {
        std::string result;
        char c;
        while (get(c)) {
            result.push_back(c);
        }
        return result;
    }

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
        char result = (char)get();
        if (result != ' ') {
            auto message = std::format("readSpace() check failed. Got {0}", result);
            throw read_format_error(message);
        }
    }

    void istream::readEOL() {
        char result = (char)get();
        if (result != '\n') {
            auto message = std::format("readEOL() check failed. Got {0}", result);
            throw read_format_error(message);
        }
    }

    void istream::readEOF() {
        char result = (char)get();
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
        if (argc != 5) {
            return 1;
        }
        input = ifstream(argv[1]);
        output = ifstream(argv[2]);
        answer = ifstream(argv[3]);
        judgement = ofstream(argv[4]);

        auto judgement_info = check();

        judgement << "status: " << judgement_info.status << "\n";
        judgement.close();
        return 0;
    }

    CheckerJudgement Checker::WA(std::string message) {
        return CheckerJudgement("WA", std::move(message));
    }

    CheckerJudgement Checker::OK(std::string message) {
        return CheckerJudgement("OK", std::move(message));
    }

    ifstream::ifstream() : filebuf(), istream(&filebuf) {}

    ifstream::ifstream(const std::string &path) : filebuf(), istream(&filebuf) {
        filebuf.open(path, std::ios::in);
    }

    ifstream::ifstream(const char* path) : filebuf(), istream(&filebuf) {
        filebuf.open(path, std::ios::in);
    }

    void ifstream::close() {
        filebuf.close();
    }

    ofstream::ofstream() : filebuf(), ostream(&filebuf) {}

    ofstream::ofstream(const std::string &path) : filebuf(), ostream(&filebuf) {
        filebuf.open(path, std::ios::out);
    }

    ofstream::ofstream(const char* path) : filebuf(), ostream(&filebuf) {
        filebuf.open(path, std::ios::out);
    }

    void ofstream::close() {
        filebuf.close();
    }
}

