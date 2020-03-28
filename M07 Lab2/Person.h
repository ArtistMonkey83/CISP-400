
//Make the representation of Person private
struct Person
{
  private:
//const member functions getName() and getAge() to read the name and age.
//check that age is [0:150) and that name doesn’t contain
//the characters ; : " ' [ ] * & ^ % $ # @ !. Use error() in case of error.
  const getName();
  const getAge();

//Define struct Person containing string name and int age.
  string name;
  int age;

//Only construct the Person if the input does not fail, otherwise it will probably throw an error on failed data.
  Person(); //default constructor
  Person(string _name, int _age); //overloaded constructor initializing name and age.


//Define an input >> and an output << operator for Person
//Assume the input and output are in the format name age
//Inside the >> operator, construct a Person with the inputs
//and assign it to the parameter
  operator >>();
  operator <<();
}
