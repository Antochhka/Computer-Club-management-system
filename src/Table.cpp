#include "../include/Table.hpp"

Table::Table(int table_id) {
    this->table_id = table_id;
    this->occupied_time = Time(0,0);
    this->occupied = false;
    this->revenue = 0;
    this->start_time = Time(0,0);
    this->end_time = Time(0,0);
}

string Table::format_table() const {
    // Формат: ID Время_начала Время_окончания Выручка Статус
    string status = this->occupied ? "Занят" : "Свободен";
    return to_string(this->table_id) + " " +
           this->start_time.get_time() + " " +
           this->end_time.get_time() + " " +
           to_string(this->revenue) + " " +
           status;
}

bool Table::is_occupied() {
    return this->occupied;
}

void Table::set_occupied(bool true_or_false) {
    this->occupied = true_or_false;
}

void Table::set_start_time(Time time) {
    this->start_time = time;
}

void Table::set_end_time(Time time) {
    this->end_time = time;
}

void Table::set_occupied_time() {
    Time temp = this->end_time - this->start_time;
    this->occupied_time = temp + this->occupied_time;
}

void Table::set_revenue(int hour_cost) {
    Time temp = end_time - start_time;
    int hours = temp.get_hours();
    this->revenue += (temp.get_minutes() > 1) ? hour_cost * (hours + 1) : 0;
}

Time Table::get_occupied_time() {
    return this->occupied_time;
}

int Table::get_revenue() {
    return this->revenue;
}


