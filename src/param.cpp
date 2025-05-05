#include "../include/param.hpp"

void check_param(int argc, char*argv[]) {
    if (argc != 2) {
        throw invalid_argument("Incorrect number of arguments, Usage: task test_file.txt");
    } else {

        string filename(argv[1]);

        if (!file_exist(filename)) {
            throw runtime_error("Filed to open file: " + filename);
        }

    }  
}

/**
 * @brief Проверяет существование файла.
 * @param filename Имя файла для проверки.
 * @return true - если файл существует, false - если нет.
 */
bool file_exist(string filename) {

    bool res = true;

    ifstream checking_file(filename);
    res = checking_file.good();
    checking_file.close();

    return res;
}