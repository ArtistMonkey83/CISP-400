/*
• Main
    ◦ Construct a Track
    ◦ Construct 2 GasolineCars and 2 HybridCars
    ◦ Loop and call driveCars for each iteration.  Output the lap #
    ◦ Give the cars 14, 12, 14, and 12 gallon tanks, respectively, and 26 laps

*/
#include "Car.h"
#include "std_lib_facilities.h"



int main()
{
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
cout << "We made it back forloop 45!\n";
  for(int i = 0; i < 26; i++) //loop to handle the laps we go around!
  {
    cout << "Lap#: " << (i+1) << endl;
cout << "We made it here49!\n";
    Sacramento500.driveCars();
cout << "We made it here 50!\n"; //never made it here Range error

  }
  cout << "The 2020 Sacramento500 has come to an end folks!";
  return 0;
}
