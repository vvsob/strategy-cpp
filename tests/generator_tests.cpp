#include <catch2/catch_test_macros.hpp>
#include <strategy.h>

std::string read_file(const std::string& path) {
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string contents = buffer.str();
    t.close();
    return std::move(contents);
}

TEST_CASE( "generator works", "[generator]" ) {
    class NumberGenerator : public strategy::Generator {
    public:
        void generate(int argc, char** argv) override {
            int n = atoi(argv[0]);
            int max_value = atoi(argv[1]);
            int seed = atoi(argv[2]);
            auto rnd = strategy::random(seed);

            output << n << "\n";
            for (int i = 0; i < n; ++i) {
                output << rnd() % max_value + 1 << (i < n - 1 ? " " : "\n");
            }
        }
    };
    char* args[] = {
            "generator",
            "tests/temp/test1.txt",
            "10",
            "100",
            "1",
    };
    auto generator = NumberGenerator();
    int exit_code = generator.main(5, args);

    REQUIRE(exit_code == 0);
    auto test1_contents = read_file("tests/temp/test1.txt");

    char* args2[] = {
            "generator",
            "tests/temp/test2.txt",
            "10",
            "100",
            "2",
    };
    int exit_code2 = generator.main(5, args2);

    REQUIRE(exit_code2 == 0);
    auto test2_contents = read_file("tests/temp/test2.txt");

    REQUIRE(test1_contents != test2_contents);

    char* args3[] = {
            "generator",
            "tests/temp/test3.txt",
            "10",
            "100",
            "2",
    };
    int exit_code3 = generator.main(5, args3);

    REQUIRE(exit_code3 == 0);
    auto test3_contents = read_file("tests/temp/test3.txt");

    REQUIRE(test2_contents == test3_contents);
}

