#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

/**
 * @class Time
 * @brief Класс для представления и операций с временем.
 *
 * Класс Time предоставляет функциональность для работы с временем
 * в 24-часовом формате, включая арифметические операции и сравнение.
 */
class Time {
    private:
        int hours;
        int minutes; 
    
        public:
        /**
         * @brief Конструктор с параметрами.
         * @param hours Часы (0-23).
         * @param minutes Минуты (0-59).
         */
        Time(int hours, int minutes);
    
        /**
         * @brief Конструктор по умолчанию.
         * Инициализирует время как 00:00.
         */
        Time();
    
        /**
         * @brief Оператор сложения времени.
         * @param other Время для сложения.
         * @return Новый объект Time с суммой времени.
         */
        Time operator+(const Time &other) const;
    
        /**
         * @brief Оператор вычитания времени.
         * @param other Время для вычитания.
         * @return Новый объект Time с разницей времени.
         */
        Time operator-(const Time &other) const;
    
        /**
         * @brief Оператор сравнения "больше".
         * @param other Время для сравнения.
         * @return true если текущее время больше other.
         */
        bool operator>(const Time &other) const;
    
        /**
         * @brief Оператор сравнения "меньше".
         * @param other Время для сравнения.
         * @return true если текущее время меньше other.
         */
        bool operator<(const Time &other) const;
    
        /**
         * @brief Оператор сравнения на равенство.
         * @param other Время для сравнения.
         * @return true если времена равны.
         */
        bool operator==(const Time &other) const;
    
        /**
         * @brief Получает строковое представление времени.
         * @return Строка в формате "HH:MM".
         */
        string get_time() const;
    
        /**
         * @brief Устанавливает новое значение времени.
         * @param h Часы (0-23).
         * @param m Минуты (0-59).
         */
        void set_time(int h, int m);
    
        /**
         * @brief Получает минуты.
         * @return Количество минут (0-59).
         */
        int get_minutes();
    
        /**
         * @brief Получает часы.
         * @return Количество часов (0-23).
         */
        int get_hours();
    };