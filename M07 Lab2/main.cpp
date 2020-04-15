/*

Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).
Read a sequence of Persons from input (cin) into a vector
Don't worry about prompting. Assume an EOF will be entered at the end of the input, causing cin to fail when there is no more input. You can enter an EOF from the command line by typing Ctrl + z in Windows and Ctrl + d in Linux to test this.
Write the contents of the vector out to the screen (cout)
*/

#include "std_lib_facilities.h"
#include "Person.h"


int main()
{
  Person p1("Goofy",63);

  cout << p1 << endl;

  vector <Person> pData;
  while (cin >> p1)
  {pData.push_back(p1);}
  for (unsigned int i = 0; i <pData.size(); i++)
  {cout << pData[i] << endl;}

  return 0;
}


/*

try
{

}
catch(runtime_error& e) {cout << e.what() << endl;}

*/
