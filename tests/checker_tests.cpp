#include <catch2/catch_test_macros.hpp>
#include <strategy.h>


TEST_CASE( "checker works", "[checker]" ) {
    class Checker : public strategy::Checker {
    public:
        strategy::CheckerJudgement check() override {
            while (true) {
                auto output_text = output.readWord();
                auto answer_text = answer.readWord();
                if (output_text.empty() && answer_text.empty()) {
                    break;
                }
                if (output_text != answer_text) {
                    return WA();
                }
            }
            return OK();
        }
    };
    char* args[] = {
            "checker",
            "tests/static/checker1/input.txt",
            "tests/static/checker1/output.txt",
            "tests/static/checker1/answer.txt",
            "tests/temp/judgement.txt"
    };
    Checker checker = Checker();
    int exit_code = checker.main(5, args);

    REQUIRE(exit_code == 0);
    std::ifstream t("tests/temp/judgement.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string judgement_contents = buffer.str();

    REQUIRE(judgement_contents == "status: OK\n");
}

