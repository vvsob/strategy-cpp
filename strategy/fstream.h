#ifndef STRATEGY_FSTREAM_H
#define STRATEGY_FSTREAM_H

#include "stream.h"

namespace strategy {
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
}

#endif //STRATEGY_FSTREAM_H
