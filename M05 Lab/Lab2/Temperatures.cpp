#include "Temperatures.h"

istream& operator>>(istream& is, Reading& r)
{
  char ch1;
  if(is>> ch1 && ch1 != '(')  //successfully reads a new character but not a new reading
  {//only go in here if we got something not the begging of a  reading
    is.unget();
    is.clear(ios_base::failbit);  //sets the failbit when we dont see a new reading
    return is;
  }
  char ch2;
  int d,h;
  double t;
  is >> d >> h >> t >> ch2;

  if(!is || ch2!= ')') error("Bad Reading!"); //something serious happend
  r.day =d;
  r.hour=h;
  r.temperature=t;
  return is;
}

istream& operator>>(istream& is, Month& m)
{
  char ch;
  if(is>> ch && ch != '{')    //Month starts with a curly bracket! if we dont see a new month set the fail bit
  {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }
  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if(!is || month_marker != "month") error("Bad start of month!");  //we only get her if we didnt read "month"
                                                                    //or if the input stream failed
  m.month = month_to_int(mm); //convert to an integer and set the member variable we need to write this helper function still
  int duplicates = 0;   //tracking dupilicates
  int invalids = 0;

  for(Reading r; is >> r;) //initialization, conidition, and update we dont need to update i overwrites r every new iteration
  {//this loop will bounce out and set fail bit in line 28
    if(is_valid(r)) //if this helper function returns true
    {
      if(m.days[r.day].hours[r.hour]!=not_a_reading)//what ever day I just read is the
                                      //one I want month keeps track of days year keeps track of months there is something there
                                      // some meber in my month m m.days[r.day] evaluates a day
                                      //each dot strips off one layer of "russian doll"
                                      //hours[r.hour] evalutes to an hour
      {
        ++duplicates;               //we are in a month if i see a reading in my data structure otherwise we have a vaild reading
      }
      m.days[r.day].hours[r.hour]= r.temperature; // if it is valid
    }
    else
      ++invalids;
  }
  if(invalids) error("invalid readings in month ", invalids);
  if(duplicates) error("duplicate readings in month ", duplicates);  //concatenates an int either invalids or duplicates value

  end_of_loop(is, '}', "bad end of month");   // if this doesn't throw it got a good closeing } bracket, send back stream
  return is;
}

istream& operator>>(istream& is, Year& y)
{
  char ch;
  is >> ch;
  if(ch !='{') //looking for the begging of the year which is a curly bracket {
  {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }
  string year_marker;
  int yy;
  is >> year_marker >>yy;
  if(!is || year_marker!= "year") error("bad start of the year"); //if stream failed or it doesn't say year throw error
  y.year=yy;
  /// for (Month m; is >> m;) a given month will have a bunch of days that aren't a reading
  //each different month will have is own vector  when we reuse the m variable we will have the new iteration and previous iteration
  //we need the m created everytime the loop iterates to make it fresh and not have left over data
  while (true)
  {
    Month m;
    if(!(is>>m)) break;
    y.months[m.month]=m; //year has a months vector we are going to populate it with everything the variable m has
                        //copying from the local variable m which will go out of scope and putting in the more permanete
                        //y.months[m.month] year is the container for the months months container for all the days
                        //days are the container for the hours
  }
  end_of_loop(is,'}',"bad end of year"); // use the } closeing curly bracket  is the end of the year character
  return is;

}

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
ostream& operator<<(ostream& os, Year& y)
{
/*  os << setprecision(2) << fixed << setw(12) << "year|" << setw(12) <<
  "Month|" << setw(12) << "day|" << setw(12) << "hour|" << setw(12) <<
  "reading|" << endl;
  for(int _month = 0; _month < 12; _month++)
  {
    if(y.month[_month].month != not_a_month])
    {os << setw(12) << y.month[_month] << '|'}
  }
*/
os << "Year: " << y.year;

  for (int month_i = 0; month_i < 12; month_i++) {
    if (y.months[month_i].month != not_a_month) {
      os << "\tMonth: " << int_to_month(month_i) << std::endl;
      for (int day_i = 1; day_i < 31; day_i++) { // list max days for each month
        os << "\t\tDay: " << day_i << std::endl;
        for (int hour_i = 0; hour_i < 24; hour_i++) {
          if (y.months[month_i].days[day_i].hours.at(hour_i) != not_a_reading) {
            os << "\t\t\tHour: " << hour_i << ", reading: "
              << y.months[month_i].days[day_i].hours.at(hour_i) << std::endl;
          }
        }
      }
    }
  }
}
///helper functions
//drill down from year, to month, to days, to reading triple for loop


///Convert "jan", "feb", … to 0, 1, …
///Use an array of strings
int month_to_int(string s)
{
  for(int i = 0; i<12; i++)//map container could be used here
  {if(month_input_tbl[i]==s)return i; return -1;} //if the string is equal to the the value return that value, else return error
}
///Check ranges on day, hour, temperature
bool is_valid(const Reading& r)
{
  if(r.day<1 || 31 < r.day) return false;
  if(r.hour<0 || 23 < r.hour) return false;
  if(r.temperature< implausible_min || implausible_max < r.temperature) return false;

  return true;
}
///Clear the fail state of the input stream for more reading
///Look for the terminating '}'
void end_of_loop(istream& ist, char term, const string& message)
{
  if(ist.fail())
  {
    ist.clear();
    char ch;
    if(ist >> ch && ch == term) return;
    error(message);
  }
}
///Convert an index to a printable month, uses an array of strings
string int_to_month(int i)
{
  if( i < 0 || i >= 12) {error("Month out of Range!");}
  return month_print_tbl[i];
}
