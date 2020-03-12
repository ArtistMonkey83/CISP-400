#include "Temperatures.h"

int main()
{
    // open an input file :
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname}; //c++ 11 or 14 otherwise this line will not work
    if (!ifs) error("can't open input file ",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit); // throw for bad()
    // open an output file :
    cout << "Please enter output file name"<< endl;
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("can't open output file ",oname);
    // read an arbitrary number of years:
    vector<Year> ys;
    while(true)
    {
        Year y; // get a freshly initialized Year each time around
        if (!(ifs>>y)) break;
        ys.push_back(y);  //read a whole year
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (Year& y : ys) ofs << y;    // operator I need to handle
    for (Year& y : ys) cout << y;   //for each loop for every year y in my vector year as rhs with in that years
                                    // loop for the months
                                    //the months have days 1-31
                                    //0-23 for the hours
                                    //y.months[i].days[j].hours[k] if its not not_a_reading then priint it
                                    
}
