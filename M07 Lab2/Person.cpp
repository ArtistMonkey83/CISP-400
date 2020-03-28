#include "Person.h"
#include "std_lib_facilities.h"

//const member functions getName() and getAge() to read the name and age.
//check that age is [0:150) and that name doesn’t contain
/*
the characters with ASCII values:
; = 59
: = 58
" = 42
' = 96
[ = 91
] = 93
* = 42
& = 38
^ = 94
% = 37
$ = 36
# = 35
@ = 64
! = 33
Use error() in case of error.
*/
  const getName()
  {
    return name;
  }
  const getAge()
  {
    return age;
  }


//Only construct the Person if the input does not fail, otherwise it will probably throw an error on failed data.
//default constructor
  Person::Person()
  {
    if (!ios::fail)
  }

//overloaded constructor initializing name and age.
  Person::Person(string _name, int _age)
  {
    if (!ios::fail)
    {
      if (string::find())
        name = _name;
        age = _age;
    }

  }

//Define an input >> and an output << operator for Person
//Assume the input and output are in the format name age
//Inside the >> operator, construct a Person with the inputs
//and assign it to the parameter
  operator >>()
  {

  }

  operator <<()
  {

  }
