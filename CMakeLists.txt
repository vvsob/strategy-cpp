cmake_minimum_required(VERSION 3.27)
project(strategy)

set(CMAKE_CXX_STANDARD 20)

include_directories(strategy)

find_package(Catch2 3 REQUIRED)

add_library(strategy STATIC
        strategy/checker.h
        strategy/fstream.h
        strategy/errors.h
        strategy/stream.h
        strategy/random.h
        strategy/stream.cpp
        strategy/checker.cpp
        strategy/fstream.cpp
        strategy/generator.cpp
        strategy/generator.h
)

add_executable(tests tests/istream_tests.cpp
        tests/random_tests.cpp
        tests/checker_tests.cpp
        tests/generator_tests.cpp)
target_link_libraries(tests PRIVATE strategy)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
