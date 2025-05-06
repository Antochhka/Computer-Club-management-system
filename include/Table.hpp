#pragma once

#include "Time.hpp"

class Table {
    private:
        int table_id; 
        bool occupied;
        int revenue;
        Time start_time;
        Time end_time;
        Time occupied_time;

    public:
        Table(int table_id);
        string format_table() const;

        bool is_occupied();

        void set_occupied(bool true_or_false);

        void set_start_time(Time time);

        void set_end_time(Time time);

        void set_occupied_time();

        void set_revenue(int hour_cost);

        Time get_occupied_time();

        int get_revenue();

        Time get_start_time();
        
        Time get_end_time();

};