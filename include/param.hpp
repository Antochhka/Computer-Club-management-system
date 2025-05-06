#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;
/**
 * @brief Проверяет корректность параметров командной строки и существование файла.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @throw invalid_argument Если количество аргументов не соответствует ожидаемому.
 * @throw runtime_error Если указанный файл не существует или не может быть открыт.
 *
 * Функция проверяет, что программа была запущена с одним аргументом (имем файла),
 * и что указанный файл существует и доступен для чтения.
 * Пример использования:
 * @code
 * check_param(argc, argv);
 * @endcode
 */
void check_param(int argc, char* argv[]);

/**
 * @brief Проверяет существование файла.
 * @param filename Имя файла для проверки.
 * @return true если файл существует и доступен, false в противном случае.
 *
 * Функция пытается открыть файл для чтения, чтобы проверить его существование.
 * Пример использования:
 * @code
 * if (file_exist("data.txt")) {
 *     // файл существует
 * }
 * @endcode
 */
bool file_exist(string filename);