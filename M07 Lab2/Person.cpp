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
  //string const Person::getName(){return name;}
  //int const Person::getAge(){return age;}
  //void setName(string _name) {name = _name;}
  //void setAge(int _age){age = _age;}

//Only construct the Person if the input does not fail, otherwise it will probably throw an error on failed data.
//default constructor
  //Person::Person()
  //{
    //if (!ios::fail) error("Input failed!");

    //name = " ";
    //age = 0;
  //}

//overloaded constructor initializing name and age.
  Person::Person(string _name, int _age)
  {
    if(_age <=150 && _age > 0) {this->age = _age;}
    else {error("Age out of range!\n");}
    for (size_t i = 0 ; i < _name.size() ; i++)
    {
      if (!((_name[i] >= 48 && _name[i] <= 57) ||
          (_name[i] >= 65 && _name[i] <= 90) ||
          (_name[i] >= 97 && _name[i] <= 122)))
     error("Invalid Character found in name!\n");
    }
    this->name = _name;

  }

//Define an input >> and an output << operator for Person
//Assume the input and output are in the format name age
//Inside the >> operator, construct a Person with the inputs
//and assign it to the parameter
  istream& operator>>(istream& is, Person& a)
  {
    string name;
    int age;

    is >> name >> age;

    if (is)
    {
      Person a1{name,age};
      a=a1;
    }
    return is;
  }

   ostream& operator<<(ostream& os, const Person& a)
  {
    os << a.getName() << " " << a.getAge() << endl;
    return os;
  }
