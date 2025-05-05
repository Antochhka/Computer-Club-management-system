#pragma once 

#include "Time.hpp"

class Event {
    private:
        Time time;
        int id;
        string name;
        int table_id;
    public:
        Event(const Time &time, int id, const string &name);
        Event(const Time &time, int id, const string &name, int table_id);

        Time get_time() const;

        int get_id() const;
        string get_name() const;
        int get_table_id() const;

        string format_event() const;

         
};