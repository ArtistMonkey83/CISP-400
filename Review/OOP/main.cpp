/*
• Main
    ◦ Construct a Track
    ◦ Construct 2 GasolineCars and 2 HybridCars
    ◦ Loop and call driveCars for each iteration.  Output the lap #
    ◦ Give the cars 14, 12, 14, and 12 gallon tanks, respectively, and 26 laps

*/
#include "Car.h"
#include "std_lib_facilities.h"
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
  //construct a Track!
  Track Sacramento500;
  //Cars to race
/*
  ElectricCar RivianR1T{1983}, // use the child data type here, not the pure virtual parent!
              RivianR1S{1985};

  ElectricCar TeslaSE{2020},
              TeslaXY{2020};
*/
  HybridCar PriusC{14},
            ChevyVolt{14};

  GasolineCar FordF150{12},
              FordExplorer{12};

  Sacramento500.attach(PriusC);
  Sacramento500.attach(ChevyVolt);
  Sacramento500.attach(FordF150);
  Sacramento500.attach(FordExplorer);
//
/*
  Sacramento500.attach(TeslaSE);
  Sacramento500.attach(TeslaXY);

  Sacramento500.attach(RivianR1S);
  Sacramento500.attach(RivianR1T);

*/
//cout << "We made it back forloop 45!\n";
  for(int i = 0; i < 26; i++) //loop to handle the laps we go around!
  {
    cout << "Lap#: " << (i+1) << endl;
//cout << "We made it here49!\n";
    Sacramento500.driveCars();
//cout << "We made it here 50!\n"; //never made it here Range error

  }
  cout << "\n\n\tThe 2020 virtual Sacramento500 has come to an end folks! \n\t\tStay safe and healthy wash your hands!";
  yoliesProgramFooter();
  return 0;
}
  //
  /*
       ______                _   _
      |  ____|              | | (_)
     | |__ _   _ _ __   ___| |_ _  ___  _ __  ___
    |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
   | |  | |_| | | | | (__| |_| | (_) | | | \__ \
  |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
  */
void displayExplanation()
{
  cout << "\n\n\nThe purpose of this program is to test my ability to properly override\na virtual function, and demonstrate parent and child classes.\n\n\n\tWelcome to the the virtual Sacramento500! SARs-CoViD-2 your proud \n\t\tsponsor this year! Everybody start your engines!\n\n\n";
}

void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "******************************** Review Exam 2 *********************************\n";
  cout << "********************************** 04-20-2020 **********************************\n";
  cout << "*********************************** CISP 400 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t****** Chīuhpōhualhuaztiliztli ******\n\n\n";
  cout << "English - Computing: Activity requiring, benefitting from or creating computers.\n\n";
  cout << "Spanish - Informática: Ciencia que estudia métodos, procesos, técnicas,con el \nfin de almacenar, procesar y transmitir información y datos en \nformato digital.\n\n";
  cout << "German - Rechnen: Tätigkeiten, die auf Computern beziehungsweise \nalgorithmischen Prozessen aufbauen.\n\n";
  cout << "Russian - компьютинг: Деятельность, требующая, использующая или \nсоздающая компьютеры.\n\n";
  cout << "French - Technologies de l'information: Activité nécessitant, \nbénéficiant de, ou créant des ordinateurs.\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}
