#include <gtest/gtest.h>
#include "../include/ComputerClub.hpp"
#include <fstream>
#include <string>
#include <cstdlib> // для std::system
#include <cstdio> // для remove
#include <algorithm>
#include <cctype>

class ClubTest : public ::testing::Test {
protected:
    std::string tempFile;

    void SetUp() override {
        tempFile = "tests/temp_test_input.txt";
        std::ofstream out(tempFile);
        out.close();
    }

    void TearDown() override {
        std::remove(tempFile.c_str());
    }
};

// Удаляет пробелы/табуляции/переводы строк справа
std::string rtrim(const std::string& s) {
    std::string result = s;
    result.erase(std::find_if(result.rbegin(), result.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());
    return result;
}

bool compareFiles(const std::string& outputFile, const std::string& expectedFile) {
    std::ifstream output(outputFile);
    std::ifstream expected(expectedFile);

    if (!output.is_open() || !expected.is_open()) {
        return false;
    }

    std::string line1, line2;
    while (std::getline(output, line1) && std::getline(expected, line2)) {
        if (rtrim(line1) != rtrim(line2)) {
            return false;
        }
    }
    // Проверяем, что оба файла закончились
    return output.eof() && expected.eof();
}

TEST_F(ClubTest, NotOpenYet) {
    // Запускаем программу и перенаправляем вывод в файл
    std::string command = "./task tests/tests_file/not_open_yet.txt > tests/temp_test_input.txt";
    int result = std::system(command.c_str());
    ASSERT_EQ(result, 0); // Проверяем, что программа завершилась успешно

    // Сравниваем вывод с ожидаемым результатом
    EXPECT_TRUE(compareFiles("tests/temp_test_input.txt", "tests/tests_file/not_open_yet_expected.txt"));
}

TEST_F(ClubTest, MinimalCase) {
    // Запускаем программу и перенаправляем вывод в файл
    std::string command = "./task tests/tests_file/minimal_case.txt > tests/temp_test_input.txt";
    int result = std::system(command.c_str());
    ASSERT_EQ(result, 0); // Проверяем, что программа завершилась успешно

    // Сравниваем вывод с ожидаемым результатом
    EXPECT_TRUE(compareFiles("tests/temp_test_input.txt", "tests/tests_file/minimal_case_expected.txt"));
}

TEST_F(ClubTest, ClientsLeft) {
    // Запускаем программу и перенаправляем вывод в файл
    std::string command = "./task tests/tests_file/clients_left.txt > tests/temp_test_input.txt";
    int result = std::system(command.c_str());
    ASSERT_EQ(result, 0); // Проверяем, что программа завершилась успешно

    // Сравниваем вывод с ожидаемым результатом
    EXPECT_TRUE(compareFiles("tests/temp_test_input.txt", "tests/tests_file/clients_left_expected.txt"));
}

TEST_F(ClubTest, LongQueue) {
    // Запускаем программу и перенаправляем вывод в файл
    std::string command = "./task tests/tests_file/long_queue.txt > tests/temp_test_input.txt";
    int result = std::system(command.c_str());
    ASSERT_EQ(result, 0); // Проверяем, что программа завершилась успешно

    // Сравниваем вывод с ожидаемым результатом
    EXPECT_TRUE(compareFiles("tests/temp_test_input.txt", "tests/tests_file/long_queue_expected.txt"));
}