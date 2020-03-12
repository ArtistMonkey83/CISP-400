#ifndef TEMPERATURES_H_INCLUDED
#define TEMPERATURES_H_INCLUDED

#include "std_lib_facilities.h"

const int not_a_reading = -7777; // less than absolute zero not a possible temperature
const int not_a_month = -1;      // not a possible month

///constexpr initializes at compile time
constexpr int implausible_min = -200;   //you could use just const, constexpr
constexpr int implausible_max = 200;    //initializes faster at compile time

struct Day
{
    ///initialize hours to a nameless vector with 24 values of not_a_reading
    ///must use {} initialization list syntax
    vector<double> hours {vector<double>(24,not_a_reading)}; //uses new features of c++
};                                                           //vector<double> hours() would be function declaration
                                                            // vector<double> {} initialization list
                                                            //24 double elements and not_a_reading is the initialization value
struct Month
{ // a month of temperature readings
    int month {not_a_month}; // [0:11] January is 0 for array indexing {} let us give it initial value
    vector<Day> days {32}; // [1:31] one vector of readings per day, skip 0
};

struct Year
{ // a year of temperature readings, organized by month
    int year; // positive == A.D.
    vector<Month> months {12}; // [0:11] January is 0
};

struct Reading
{ //struct for holding our data while we are reading it in, temporary before we load up days, months, years
    int day;
    int hour;
    double temperature;
};

istream& operator>>(istream& is, Reading& r); //operator to read a Reading
istream& operator>>(istream& is, Month& m);   //operator to read a Month
istream& operator>>(istream& is, Year& y);    //operator to read a year
// Reading operator will read till it fails and then move onto the Month, and then when that operator fails it will move onto year operator




///Print each reading for every month, day, and hour within Year& y
///Use a triple nested for loop for 12 months, 31 days per month, and 24 hours per day
///print each reading in the following format:
///set os precision to 2, fixed point
///field width 12, separated by '|'
///         year|       Month|         day|        hour|     reading|
///example:
///         2018|     January|          30|           7|       62.12|
///The member access operator . is your friend
///string int_to_month(int i)   to convert a month index to a printable string
///only print if the reading != not_a_reading
ostream& operator<<(ostream& os, Year& y);

///helper functions

///Convert "jan", "feb", … to 0, 1, …
///Use an array of strings
int month_to_int(string s);

///Check ranges on day, hour, temperature
bool is_valid(const Reading& r);

///Clear the fail state of the input stream for more reading
///Look for the terminating '}'
void end_of_loop(istream& ist, char term, const string& message);

///Convert an index to a printable month, uses an array of strings
string int_to_month(int i);

///index to string conversion arrays
//all possible strings we could have for month 
const vector<string> month_input_tbl =
{
    "jan", "feb", "mar", "apr", "may", "jun", "jul",
    "aug", "sep", "oct", "nov", "dec"
};

const vector<string> month_print_tbl =
{
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

#endif // TEMPERATURES_H_INCLUDED
