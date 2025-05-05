#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;
/**
 * @brief Проверяет аргументы командной строки и возможность создания файла
 * 
 * @param argc Количество аргументов (должно быть равно 2)
 * @param argv Массив аргументов (argv[1] - имя выходного файла)
 * 
 * @throw invalid_argument Если передано неверное количество аргументов
 * @throw runtime_error Если не удалось открыть указанный файл для записи
 * 
 * @note При успешной проверке создает пустой файл, который автоматически закрывается
 * @example Правильный вызов: ./program output.txt
 */
void check_param(int argc, char*argv[]);

bool file_exist(string filename);