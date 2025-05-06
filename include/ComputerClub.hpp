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
#define LEAVE 4

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
        ComputerClub(int table_count, int hour_cost, const Time &open_time, const Time &close_time, const vector<Event> &input_event, vector<Table> &tables);
        ComputerClub();

        void process_event();

        void process_come_to_the_club(Event &event);

        void generate_output_event(const Event &event);

        void process_sit_at_table(Event &event);

        void process_wait_in_queue(Event &event);

        void process_leave(Event &event);

        void leave_last_client();

        void revenue_calculation();

};