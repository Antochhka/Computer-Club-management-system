#include "../include/Parser.hpp"
#include <gtest/gtest.h>

TEST(ParserTest, ValidInputFile) {
    std::string filename = "tests/tests_file/valid_input.txt";
    EXPECT_NO_THROW({
        ComputerClub club = Parser::parser(filename);
    });
}

TEST(ParserTest, ValidFullTime) {
    std::string filename = "tests/tests_file/valid_fulltime.txt";
    EXPECT_NO_THROW({
        ComputerClub club = Parser::parser(filename);
    });
}

TEST(ParserTest, InvalidTime) {
    std::string filename = "tests/tests_file/invalid_time.txt";
    EXPECT_THROW({
        ComputerClub club = Parser::parser(filename);
    }, std::invalid_argument);
}

TEST(ParserTest, InvalidCntTable) {
    std::string filename = "tests/tests_file/invalid_cnt_tab.txt";
    EXPECT_THROW({
        ComputerClub club = Parser::parser(filename);
    }, std::invalid_argument);
}
