#include "Chrono.h"
#include "../std_lib_facilities.h"

using namespace Chrono; //this prevents having to use Chrono::

int main()
{
    try
    {
        Date d1;
        cout << "default: " << d1 << endl;  ///use overloaded <<

        Date d2(2019, Month::dec, 31);
        cout << "today: " << d2 << endl;

        //checking invalid date Date d3(2018, Month::feb, 99);

        Date d4;
          //tsting default constructor cout << "test: " << d4 << endl;
          cout << "Type a date in the format '(Y, M, D)': ";
          cin >> d4;  ///use overloaded >>

          if(!cin)
          {
              cout << "Format error." << endl;
              cin.clear();  ///clear fail flag
              cin.ignore(256, '\n');  ///clear read buffer
          }

          ///use overloaded == and !=
          if(d4 == d2)
          {
              cout << "That IS today's date!" << endl;
          }
          else if(d4 != d2)
          {
              cout << "That is NOT today's date!" << endl;
          }

          d2.add_day();
          cout << "Tomorrow's date: " << d2 << endl;

          d4.add_day();
          cout << "The day after the date entered: " << d4 << endl;

    }
    catch(Date::invalid)
    {
        cout << "Invalid date!" << endl;
    }

/*
cout << d<< endl;
d.add_day();
cout << d << endl;
*/
}
