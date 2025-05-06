#pragma once

#include <vector>
#include <map>
#include <set>
#include <queue>

#include "Time.hpp"
#include "Event.hpp"
#include "Table.hpp"

#define CAME_TO_THE_CLAB 1 // Пришел в клуб
#define SIT_AT_TABLE 2 // Сел за стол
#define WAIT_IN_QUEUE 3 // Ждет в очереди
#define LEAVE 4 // Ушел из клуба

/**
 * @class ComputerClub
 * @brief Класс, реализующий логику работы компьютерного клуба.
 *
 * Класс обрабатывает все события, происходящие в клубе, управляет клиентами,
 * столами и очередью, а также рассчитывает выручку.
 */
class ComputerClub {
    private:
        int table_count;
        int hour_cost;
        Time open_time;
        Time close_time;
        vector<Event> input_event;
        vector <Table> tables;
        set<string> clients_in_club;
        map<string, int> clients_at_table;
        queue<string> waiting_queue;
        vector<Event> output_event;

        public:
        /**
         * @brief Основной конструктор клуба.
         * @param table_count Количество столов в клубе.
         * @param hour_cost Стоимость часа аренды стола.
         * @param open_time Время открытия клуба.
         * @param close_time Время закрытия клуба.
         * @param input_event Входные события.
         * @param tables Вектор столов клуба.
         */
        ComputerClub(int table_count, int hour_cost, const Time &open_time, 
                    const Time &close_time, const vector<Event> &input_event, 
                    vector<Table> &tables);
    
        /**
         * @brief Конструктор по умолчанию.
         */
        ComputerClub();
    
        /**
         * @brief Основной метод обработки событий.
         * 
         * Выводит время открытия, обрабатывает все события и выводит результаты.
         */
        void process_event();
    
        /**
         * @brief Рассчитывает и выводит выручку по всем столам.
         */
        void revenue_calculation();
    
        /**
         * @brief Обрабатывает уход клиентов при закрытии клуба.
         * 
         * Вызывает событие ухода для всех оставшихся клиентов в алфавитном порядке.
         */
        void leave_last_client();
    
        /**
         * @brief Обрабатывает событие ухода клиента.
         * @param event Событие ухода.
         */
        void process_leave(Event &event);
    
        /**
         * @brief Обрабатывает событие ожидания в очереди.
         * @param event Событие ожидания.
         */
        void process_wait_in_queue(Event &event);
    
        /**
         * @brief Обрабатывает событие занятия стола.
         * @param event Событие занятия стола.
         */
        void process_sit_at_table(Event &event);
    
        /**
         * @brief Обрабатывает событие прихода клиента.
         * @param event Событие прихода.
         */
        void process_come_to_the_club(Event &event);
    
        /**
         * @brief Генерирует вывод события.
         * @param event Событие для вывода.
         */
        void generate_output_event(const Event &event);
        };