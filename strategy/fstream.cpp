#include "fstream.h"

namespace strategy {
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