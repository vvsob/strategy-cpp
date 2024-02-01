#ifndef STRATEGY_STREAM_H
#define STRATEGY_STREAM_H

#include <fstream>

namespace strategy {
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
}

#endif //STRATEGY_STREAM_H
