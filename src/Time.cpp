#include "../include/Time.hpp"


Time::Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
}

Time::Time() {
    this->hours = 0;
    this->minutes = 0;
}

Time Time::operator+(const Time &other) const {
    int mins = this->minutes + other.minutes;
    int hrs = this->hours + other.hours + mins / 60;
    mins %= 60;
    return Time(hrs, mins);
}

Time Time::operator-(const Time &other) const {
    int total1 = this->hours * 60 + this->minutes;
    int total2 = other.hours * 60 + other.minutes;
    int diff = total1 - total2;
    int hrs = diff / 60;
    int mins = diff % 60;
    return Time(hrs, mins);
}

bool Time::operator>(const Time &other) const {
    return (this->hours > other.hours) ||
           (this->hours == other.hours && this->minutes > other.minutes);
}

bool Time::operator<(const Time &other) const {
    return (this->hours < other.hours) ||
           (this->hours == other.hours && this->minutes < other.minutes);
}

bool Time::operator==(const Time &other) const {
    return this->hours == other.hours && this->minutes == other.minutes;
}

string Time::get_time () const {
    string hours = (this->hours >= 10) ? to_string(this->hours) : "0" + to_string(this->hours);
    string minutes = (this->minutes >= 10) ? to_string(this->minutes) : "0" + to_string(this->minutes);
    return hours + ":" + minutes;

}

void Time::set_time(int h, int m) {
    this->hours = h;
    this->minutes = m;
}

int Time::get_minutes() {
    return this->minutes;
}

int Time::get_hours() {
    return this->hours;
}
