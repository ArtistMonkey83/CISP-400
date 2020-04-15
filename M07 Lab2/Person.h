#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "../std_lib_facilities.h"

//Make the representation of Person private
struct Person
{
  //  void setName(string _name);
  //  void setAge(int _age);


//const member functions getName() and getAge() to read the name and age.
//check that age is [0:150) and that name doesn’t contain
//the characters ; : " ' [ ] * & ^ % $ # @ !. Use error() in case of error.
    string getName()const {return name;};
    int getAge()const {return age;};


//Only construct the Person if the input does not fail, otherwise it will probably throw an error on failed data.
    Person(): name(""), age(0){}; //default constructor
    Person( string _name, int _age); //overloaded constructor initializing name and age.

  private:
//Define struct Person containing string name and int age.
    string name;
    int age;

};
//Define an input >> and an output << operator for Person
//Assume the input and output are in the format name age
//Inside the >> operator, construct a Person with the inputs
//and assign it to the parameter
    istream& operator>>(istream& is, Person& a);
    ostream& operator<<(ostream& os, const Person& a);

#endif //PERSON_H_INCLUDED
