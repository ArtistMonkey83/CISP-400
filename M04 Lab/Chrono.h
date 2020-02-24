#ifndef DATE_h
#define DATE_h

#include "../std_lib_facilities.h"

namespace Chrono
{
enum class Month {
  jan=1, feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date // uses Month
{
public:
    class invalid{};
    Date(int y, Month m, int d);

    Date();  //default constructor

    int day() const {return d;}
    Month month() const{return m;}   //refering to the Month class
    int year() const {return y;}     //const in front of curly braces makes the function constant
                                    //Month& month() const{return m;} can actually change value
    void add_day(); // parameters?

  private:
    int y;
    Month m;
    int d;

    bool is_valid(int yy, Month mm, int dd);
    int nDays(Month m);
};

Month operator++(Month& m);
Month operator+(const Month& m, int nMonths);
Month operator+=(Month& m, int nMonths);

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);
}
#endif
