#include "../include/ComputerClub.hpp"

ComputerClub::ComputerClub(int table_count, int hour_cost, const Time &open_time, const Time &close_time, const vector<Event> &input_event, vector<Table> &tables): open_time(open_time), close_time(close_time) {
    this->table_count = table_count;
    this->hour_cost = hour_cost; 
    this->input_event = input_event;
    this->tables = tables;
}

ComputerClub::ComputerClub() {};


void ComputerClub::process_event() {
    for (auto &event: input_event) {
        generate_output_event(event);
       int id = event.get_id();
        if (id == CAME_TO_THE_CLAB) {
            this->process_come_to_the_club(event);
        } else if (id == SIT_AT_TABLE) {
            this->process_sit_at_table(event);
        } else if (id == WAIT_IN_QUEUE) {

        }
    }

    cout << this->tables[0].get_occupied_time().get_time() + " " << this->tables[0].get_revenue() << endl;
}

void ComputerClub::process_wait_in_queue(Event &event) {

}

void ComputerClub::process_sit_at_table(Event &event) {
    Time event_time = event.get_time();
    string client_name = event.get_name();
    int table_id = event.get_table_id();

    if (this->clients_in_club.find(client_name) == clients_in_club.end()) {
        generate_output_event(Event(event_time, 13, "ClientUnknown"));
        return;
    }

    if (this->tables[table_id - 1].is_occupied()) {
        generate_output_event(Event(event_time, 13, "PlaceIsBusy"));
        return;
    }

    if (this->clients_at_table.find(client_name) != clients_at_table.end()) {
        Table &occupied_now = this->tables[this->clients_at_table[client_name]];
        occupied_now.set_end_time(event_time);
        occupied_now.set_occupied_time();
        occupied_now.set_revenue(this->hour_cost);
        occupied_now.set_start_time(Time(0,0));
        occupied_now.set_end_time(Time(0,0));
        occupied_now.set_occupied(false);
        clients_at_table.erase(client_name);
    }

    clients_at_table[client_name] = table_id - 1;
        Table &this_table = this->tables[table_id - 1];
        this_table.set_occupied(true);
        this_table.set_start_time(event_time);

}

void ComputerClub::process_come_to_the_club(Event &event) {
    Time event_time = event.get_time();

    if (event_time < open_time || event_time > close_time) {
        generate_output_event(Event(event_time, 13, "NotOpenYet"));
        return;
    }

    if (clients_in_club.find(event.get_name()) != clients_in_club.end()) {
        generate_output_event(Event(event_time, 13, "YouShallNotPass"));
        return;
    }

    clients_in_club.insert(event.get_name());
}

void ComputerClub::generate_output_event(const Event &event) {

    int id = event.get_id();
    string res;
    if (id == 2) {
        res = event.get_time().get_time() + " " + to_string(event.get_id()) + " " + event.get_name() + " " + to_string(event.get_table_id()) + "\n";
    } else {
        res = event.get_time().get_time() + " " + to_string(event.get_id()) + " " + event.get_name() + "\n";
    }

    cout << res;
}

