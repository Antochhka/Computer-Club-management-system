#include "../include/Event.hpp"

Event::Event(const Time &time, int id, const string &name) : time(time){
    this->id = id;
    this->name = name;
    this->table_id = 0;
}

Event::Event(const Time &time, int id, const string &name, int table_id): time(time) {
    this->id = id;
    this->name = name;
    this->table_id = table_id;
}

Time Event::get_time() const{
    return time;
}

int Event::get_id() const {
    return id;
}

string Event::get_name() const{
    return name;
}

int Event::get_table_id() const{
    return table_id;
}

string Event::format_event() const {
    return time.get_time() + " " + to_string(id) + " " + name  + " " + to_string(table_id) + "\n";
}
