#include "../include/Parser.hpp"

ComputerClub Parser::parser(string &filename) {

    int table_count = 0, hour_cost = 0;
    Time open_time, close_time;
    vector<Event> input_event;
    vector<Table> tables;

    ifstream input_file(filename);

    string line;

    if (input_file.is_open()) {

        int counter_line = 1;

       while (getline(input_file, line)) {

            Parser::valid_line(line, counter_line);
            if (counter_line == 1) {
                table_count = stoi(line);
            } else if (counter_line == 2) {
                stringstream ss(line);
                string first_time, second_time;
                ss >> first_time >> second_time;
                pair<int,int> time;
                time = parse_time(first_time);
                open_time.set_time(time.first, time.second);
                time = parse_time(second_time);
                close_time.set_time(time.first, time.second);
            } else if (counter_line == 3){
                hour_cost = stoi(line);
            } else {
                input_event.push_back(parse_event(line, table_count));
                if (counter_line >= 5) {
                    int i = counter_line - 4;
                    if (input_event[i].get_time() < input_event[i-1].get_time()) {
                        throw invalid_argument("invalid line: " + line);
                    }
                }

            }
            counter_line++;

       }

       input_file.close();
    }

    for (int i = 0; i < table_count; i++) {
        tables.push_back(Table(i+1));
    }

    ComputerClub club(table_count, hour_cost, open_time, close_time, input_event, tables);

    return club;
}

bool Parser::valid_line(string &line, int &counter_line) {

    if (counter_line == 1 && !is_positive_number(line)) {
        throw invalid_argument("invalid line: " + line);
    } else if (counter_line == 2 && !is_valid_time_interval(line)) {
        throw invalid_argument("invalid line: " + line);
    } else if (counter_line == 3 && !is_positive_number(line)) {
        throw invalid_argument("invalid line: " + line);     
    } 

    return true;
}

bool Parser::is_positive_number(const string &line) {
    return regex_match(line, regex("^[1-9][0-9]*$"));
}


bool Parser::is_valid_time_interval(const string &line) {
    return regex_match(line, regex("^[0-9][0-9]:[0-9][0-9] [0-9][0-9]:[0-9][0-9]$"));
}

pair<int, int> Parser::parse_time(const string &time) {
    int h, m;
    sscanf(time.c_str(), "%d:%d", &h, &m);
    return {h, m};
}

Event Parser::parse_event(const string &line, int table_count) {

   stringstream ss(line);

   string time, id, name, id_table;
   ss >> time >> id >> name >> id_table;

   string expr_time = "^[0-9][0-9]:[0-9][0-9]";
   string expr_id = "[1-4]";
   string expr_name = "[a-z0-9_-]+";

   string expr_id_table = "(";
    for (int i = 1; i <= table_count; ++i) {
        if (i > 1) expr_id_table += "|";
        expr_id_table += to_string(i);
    }
    expr_id_table += ")";

    if (!regex_match(time, regex(expr_time)) || !regex_match(id, regex(expr_id)) || !regex_match(name, regex(expr_name))) {
        throw invalid_argument("invalid line: " + line);
    }

    if (stoi(id) == 2 && !regex_match(id_table, regex(expr_id_table))) {
        throw invalid_argument("invalid line: " + line);
    }

    pair<int, int> time_point = parse_time(time);
    Time res_time(time_point.first, time_point.second);

    int res_id = stoi(id);

    if (res_id == 2) {
        int res_id_table = stoi(id_table);
        return Event(res_time, res_id, name, res_id_table);
    } else {
        return Event(res_time, res_id, name);
    }
}


