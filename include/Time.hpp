#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;
/**
 * @brief Класс для представления времени (часы и минуты).
 */   
class Time {
    private:
        int hours;   ///< Часы
        int minutes; ///< Минуты
    
    public:
        /**
         * @brief Конструктор класса Time.
         * @param hours Часы.
         * @param minutes Минуты.
         */
        Time(int hours, int minutes);
        Time();
    
        /**
         * @brief Сложение двух объектов Time.
         * @param other Второй объект Time.
         * @return Новый объект Time — сумма.
         */
        Time operator+(const Time &other) const;
    
        /**
         * @brief Вычитание двух объектов Time.
         * @param other Второй объект Time.
         * @return Новый объект Time — разность.
         */
        Time operator-(const Time &other) const;
    
        /**
         * @brief Сравнение на больше.
         * @param other Второй объект Time.
         * @return true, если текущий объект больше other.
         */
        bool operator>(const Time &other) const;
    
        /**
         * @brief Сравнение на меньше.
         * @param other Второй объект Time.
         * @return true, если текущий объект меньше other.
         */
        bool operator<(const Time &other) const;
    
        /**
         * @brief Проверка на равенство.
         * @param other Второй объект Time.
         * @return true, если объекты равны.
         */
        bool operator==(const Time &other) const;

        /**
         * @brief Возращает время в виде строки в формате hh:mm
         * @return Время в виде строки
         */
        string get_time () const;

        void set_time(int h, int m);

        int get_minutes();

        int get_hours();
        
    };