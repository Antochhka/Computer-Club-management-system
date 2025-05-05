#pragma once

#include "ComputerClub.hpp"

class Parser {
    public:
            /**
         * @brief Парсит файл с событиями клуба.
         * @param filename Имя файла с входными данными.
         * @return Заполненный объект ComputerClub.
         */
        static ComputerClub parser(string &filename);

        /**
         * @brief Проверяет валидность строки по номеру строки.
         * @param line Проверяемая строка.
         * @param counter_line Номер текущей строки.
         * @return true, если строка валидна.
         * @throw invalid_argument если строка некорректна.
         */
        static bool valid_line(string &line, int &counter_line);

        /**
         * @brief Проверяет, что строка является положительным числом.
         * @param line Проверяемая строка.
         * @return true, если строка положительное число.
         */
        static bool is_positive_number(const string &line);

        /**
         * @brief Проверяет, что строка соответствует формату времени (две пары HH:MM через пробел).
         * @param line Проверяемая строка.
         * @return true, если формат времени корректен.
         */
        static bool is_valid_time_interval(const string &line);

        /**
         * @brief Преобразует строку времени "HH:MM" в пару (часы, минуты).
         * @param time Строка времени.
         * @return Пара (часы, минуты).
         */
        static pair<int, int> parse_time(const string &time);
        /**
         * @brief Парсит строку события, проверяет форматы, возвращает Event.
         * @param line Строка события.
         * @param table_count Количество столов.
         * @return Объект события Event.
         * @throw invalid_argument если строка не соответствует формату.
         */
        static Event parse_event(const string &line, int table_count);
};