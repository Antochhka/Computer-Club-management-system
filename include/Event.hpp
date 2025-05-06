#pragma once 

#include "Time.hpp"

/**
 * @class Event
 * @brief Класс, представляющий событие в системе управления компьютерным клубом.
 *
 * Класс Event инкапсулирует информацию о событиях, таких как приход клиента, 
 * смена стола, ожидание, уход или ошибки. Предоставляет методы для доступа 
 * к данным события и их форматирования для вывода.
 */
class Event {
    private:
        Time time;
        int id;
        string name;
        int table_id;
        public:
        /**
         * @brief Конструктор события с временем, ID и именем клиента.
         * @param time Время события.
         * @param id ID события
         * @param name Имя клиента, связанного с событием.
         */
        Event(const Time &time, int id, const string &name);
    
        /**
         * @brief Конструктор события с временем, ID, именем клиента и ID стола.
         * @param time Время события.
         * @param id ID события
         * @param name Имя клиента, связанного с событием.
         * @param table_id ID стола, связанного с событием (если применимо).
         */
        Event(const Time &time, int id, const string &name, int table_id);
    
        /**
         * @brief Возвращает время события.
         * @return Объект Time, представляющий время события.
         */
        Time get_time() const;
    
        /**
         * @brief Возвращает ID события.
         * @return Целое число, представляющее ID события.
         */
        int get_id() const;
    
        /**
         * @brief Возвращает имя клиента, связанного с событием.
         * @return Строка с именем клиента.
         */
        string get_name() const;
    
        /**
         * @brief Возвращает ID стола, связанного с событием.
         * @return Целое число, представляющее ID стола (0, если не применимо).
         */
        int get_table_id() const;
    
        /**
         * @brief Форматирует событие в строку для вывода.
         * @return Строка в формате "HH:MM ID Имя ID_стола".
         *
         * Пример: "09:00 1 client1 0"
         */
        string format_event() const;
    };