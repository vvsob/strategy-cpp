#include "generator.h"

namespace strategy {
    int Generator::main(int argc, char **argv) {
        if (argc < 2) {
            return 1;
        }
        output = ofstream(argv[1]);

        generate(argc - 2, argv + 2);

        output.close();
        return 0;
    }
}
