#include "Employee.h"

int main()
{
  EmployeeStaff e1("Yolie", 83);
  EmployeeManager e2("RitaRoo", 36, 45);//ask for people managed?

  printEmployee(&e1);
  printEmployee(&e2);

  cout << "\nAnnual Bonus: " << e2.getAnnualBonus() << endl;
}
