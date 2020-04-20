#include "Employee.h"

/*
      ______                _   _               _____           _     _______
    |  ____|              | | (_)             |  __ \         | |   |__   __|
   | |__ _   _ _ __   ___| |_ _  ___  _ __   | |__) | __ ___ | |_ ___ | |_   _ _ __   ___  ___
  |  __| | | | '_ \ / __| __| |/ _ \| '_ \  |  ___/ '__/ _ \| __/ _ \| | | | | '_ \ / _ \/ __|
 | |  | |_| | | | | (__| |_| | (_) | | | | | |   | | | (_) | || (_) | | |_| | |_) |  __/\__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| |_|   |_|  \___/ \__\___/|_|\__, | .__/ \___||___/
                                                                       __/ | |
                                                                      |___/|_|
*/

void yoliesProgramHeader();
void yoliesProgramFooter();
void displayExplanation();

/*
     __  __       _         ______                _   _
    |  \/  |     (_)       |  ____|              | | (_)
   | \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
  | |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
 | |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/
int main()
{
  yoliesProgramHeader();
  displayExplanation();

  EmployeeStaff e1("Yolie", 83);
  EmployeeManager e2("RitaRoo", 36, 45);//ask for people managed?

  printEmployee(&e1);
  printEmployee(&e2);

  cout << "Annual Bonus: " << e2.getAnnualBonus() << endl;

  yoliesProgramFooter();
}

/*
     ______                _   _
    |  ____|              | | (_)
   | |__ _   _ _ __   ___| |_ _  ___  _ __  ___
  |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |  | |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/

void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "********************************** Review Exam 2 *******************************\n";
  cout << "*********************************** 04-19-2020 *********************************\n";
  cout << "*********************************** CISP 400 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\n\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t****** Chīuhpōhualhuaztiliztli ******\n\n\n";
  cout << "English - Computing: Activity requiring, benefitting from or creating computers.\n\n";
  cout << "Spanish - Informática: Ciencia que estudia métodos, procesos, técnicas,con el \nfin de almacenar, procesar y transmitir información y datos en \nformato digital.\n\n";
  cout << "German - Rechnen: Tätigkeiten, die auf Computern beziehungsweise \nalgorithmischen Prozessen aufbauen.\n\n";
  cout << "Russian - компьютинг: Деятельность, требующая, использующая или \nсоздающая компьютеры.\n\n";
  cout << "French - Technologies de l'information: Activité nécessitant, \nbénéficiant de, ou créant des ordinateurs.\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}

void displayExplanation()
{
cout << "\t\tThe purpose of this project is to \n\t\ttest my ability to properly implement Polymorphism.\n";

}
