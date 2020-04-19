#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "std_lib_facilities.h"

class Employee
{
  public:
    Employee(string _name, int _salary)
    {name = _name; salary = _salary;}

    virtual void printInfo() const = 0; // pure virtual function
    virtual int getAnnualBonus() const {return 0;}
    //const int getAnnualBonus() {return 0;}

  protected:
    string name;
    int salary;
};

void printEmployee(Employee* e);

class EmployeeStaff : public Employee
{
  public:
    EmployeeStaff(string _name, int _salary) : Employee(_name,_salary){};
    void printInfo() const override;
    //int getAnnualBonus() const override;
};

class EmployeeManager : public Employee
{
  public:
    //call the parent Constructor DONT FORGET!
    EmployeeManager(string _name, int _salary, int _numManaged) : Employee(_name, _salary)
    {numManaged = _numManaged;}

    //print "Manager" then name and Salary
    void printInfo() const override;
    int getAnnualBonus() const override;
  private:
    int numManaged;
};

#endif //EMPLOYEE_H Included
