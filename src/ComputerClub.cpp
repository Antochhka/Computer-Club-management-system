#include "../include/ComputerClub.hpp"

ComputerClub::ComputerClub(int table_count, int hour_cost, const Time &open_time, const Time &close_time, const vector<Event> &input_event, vector<Table> &tables): open_time(open_time), close_time(close_time) {
    this->table_count = table_count;
    this->hour_cost = hour_cost; 
    this->input_event = input_event;
    this->tables = tables;
}

ComputerClub::ComputerClub() {};


void ComputerClub::process_event() {
    cout << this->open_time.get_time() << endl;
    for (auto &event: input_event) {
        generate_output_event(event);
       int id = event.get_id();
        if (id == CAME_TO_THE_CLAB) {
            this->process_come_to_the_club(event);
        } else if (id == SIT_AT_TABLE) {
            this->process_sit_at_table(event);
        } else if (id == WAIT_IN_QUEUE) {
            this->process_wait_in_queue(event);
        } else if (id == LEAVE) {
            process_leave(event);
        }
    }

    leave_last_client();
    revenue_calculation();


}

void ComputerClub::revenue_calculation() {
    for (size_t i = 0; i < this->tables.size(); i ++) {
        cout << i + 1 << " " << tables[i].get_revenue() << " " << tables[i].get_occupied_time().get_time() << endl;
    }
}

void ComputerClub::leave_last_client() {

    vector<string> remaining_client;

    for (string client : this->clients_in_club) {
        remaining_client.push_back(client);

        if (clients_at_table.find(client) != clients_at_table.end()) {
            int table_id = clients_at_table[client];
            Table &occupied_now = tables[table_id];

            // Устанавливаем время окончания и вычисляем выручку
            occupied_now.set_end_time(this->close_time);
            occupied_now.set_occupied_time();

            occupied_now.set_revenue(this->hour_cost);

            // Освобождаем стол
            occupied_now.set_occupied(false);
            occupied_now.set_start_time(Time(0, 0));
            occupied_now.set_end_time(Time(0, 0));
        }
    }

    sort(remaining_client.begin(), remaining_client.end());

    for (string &client : remaining_client) {
        generate_output_event(Event(this->close_time, 11, client));
    }

    cout << this->close_time.get_time() << endl;
}

void ComputerClub::process_leave(Event &event) {
    string client_name = event.get_name();
    Time event_time = event.get_time();

    if (clients_in_club.find(client_name) == clients_in_club.end()) {
        generate_output_event(Event(event_time, 13, "ClientUnknown"));
        return;
    }

    // Проверяем, сидит ли клиент за столом
    if (clients_at_table.find(client_name) != clients_at_table.end()) {
        int table_id = clients_at_table[client_name];
        Table &occupied_now = tables[table_id];

        // Устанавливаем время окончания и вычисляем выручку
        occupied_now.set_end_time(event_time);
        occupied_now.set_occupied_time();
        occupied_now.set_revenue(hour_cost);

        // Освобождаем стол
        occupied_now.set_occupied(false);
        occupied_now.set_start_time(Time(0, 0));
        occupied_now.set_end_time(Time(0, 0));
        clients_at_table.erase(client_name);

        // Если есть очередь, сажаем следующего клиента
        if (!waiting_queue.empty()) {
            string next_client = waiting_queue.front();
            waiting_queue.pop();
            clients_at_table[next_client] = table_id;
            occupied_now.set_occupied(true);
            occupied_now.set_start_time(event_time);
            generate_output_event(Event(event_time, 12, next_client, table_id));
        }
    }

    // Удаляем клиента из клуба
    clients_in_club.erase(client_name);
}

void ComputerClub::process_wait_in_queue(Event &event) {

    string client_name = event.get_name();
    Time event_time = event.get_time();

    bool free_table = false;

    for (Table &table : this->tables) {
        if (!table.is_occupied()) {
            free_table = true;
            break;
        }
    }

    if (free_table) {
        generate_output_event(Event(event_time, 13, "ICanWaitNoLonger"));
        return;
    }

    if (this->waiting_queue.size() >= size_t(this->table_count)) {
        generate_output_event(Event(event_time, 11, client_name));
        this->clients_in_club.erase(client_name);
    }

    this->waiting_queue.push(client_name);
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

