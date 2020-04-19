/*
    • Constructors
        ◦ The constructor in Employee assigns its corresponding member variables.
        ◦ In EmployeeStaff, call the parent constructor.
        ◦ In EmployeeManager, assign numManaged and call the parent constructor.
    • printInfo
        ◦ Print "Staff" or "Manager", depending on which class you are in, then name and salary
    • getAnnualBonus
        ◦ In EmployeeManager return salary * 0.1 + numManaged * 500
        ◦ In Employee return 0
    • Additional Code
        ◦ void printEmployee(Employee* e);
            ▪ Call printInfo on e (use the -> operator to access members of a pointer)
            ▪ Call getAnnualBonus on e to output the annual Bonus
        ◦ main
            ▪ construct an EmployeeStaff and an EmployeeManager
            ▪ pass their addresses (use the & operator to get the address of a variable) into printEmployee
            ▪ Call getAnnualBonus on the EmployeeManager object from main
                • Why are the outputs different?
                • Fix your code so the outputs are the same!
*/
//Employee
//#name : string
//#salary : int
//Employeet(_name : string, _salary : int)
//printInfor() const : virtual void =0
//getAnnual Bonus const : int

//EmployeeStaff : Employee
//EmployeeStaff(_name ; string, _salary : int)
//printInfor() const override : void

//EmployeeManager : Employee
//- int numManaged
//EmployeeManager(_name : string, _salary : int, numManaged : int)
//printInfo() const override : void
//getAnnualBonus() const : int
#include"Employee.h"
////////First Try///////
/*void printEmployee(Employee* e)
{
  e->printInfo();
  //e->getAnnualBonus();
  if(e-> getAnnualBonus() !=0)
  {cout < "Employee's Annual Bonus: " << e->getAnnualBonus() << endl;}
}
*/
void printEmployee(Employee* e)
{
  e->printInfo();
  cout << endl,
  e->getAnnualBonus();
}

void EmployeeStaff::printInfo() const
{cout << "\nStaff: " << name << " Salary: " << salary << endl;}


///is this finished?
int EmployeeManager::getAnnualBonus() const {return numManaged*45 + salary*0.2;} //salary *0.1 + numManaged *500;????

void EmployeeManager:: printInfo() const
{ cout << "\nManager " << name << " Salary: " << salary << endl;}
