#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "std_lib_facilities.h"

class Employee
{
  public:
    Employee(string _name, int _salary)
    {name = _name; salary = _salary;}

    virtual void printInfo() const = 0; // pure virtual function
    virtual int getAnnualBonus() const ={return 0;}

  protected:
    string name;
    int salary;
};

class EmployeeStaff : public Employee
{
  public:
    EmployeeStaff(string _name, int _salary) :Employee{}///finish!!
    void printInfo() const override;
    //int getAnnualBonus() const override;
};

class EmployeeManager : puble Employee
{
  public:
    //call the parent Constructor
    EmployeeManager(string _name, int _salary, int _numManaged)
    {
      numManaged = _numManaged;
      //cout << "Num Managed " << numManaged;
    }

    //print "Manager" then name and Salary
    void printInfo() const override;
    int getAnnualBonus() const override;
  private:

};

#edif //EMPLOYEE_H Included
