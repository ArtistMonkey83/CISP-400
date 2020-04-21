/*
Object Oriented Programming
    • For the following code, inline functions are okay, just denote what code is in the .h file and what is in the .cpp file.

*/
//Track : Car
//-cars : vector<Car*>
//+driveCars() : void
//+attach(c : Car&) : void
#include "Car.h"

//the child class calls the parents constructor!! Dont forget!
//GasolineCar::GasolineCar(double _fuelGallons) : Car(_fuelGallons){}
//this is declared in the h file!

void GasolineCar::drive(double speedMPH, double timeH)
{
  double mpg = 0.0;/// miles/mpg to
  if(speedMPH <= 45)
  {
    mpg = 43.0;
  }
  else if ( speedMPH == 55)
  {
    mpg = 45.0;
  }
  else if (speedMPH == 65)
  {mpg = 38.0;}
  else
  {
  mpg = 32.0;
  }

  double distance = speedMPH * timeH;
  double fuelUsed = distance / mpg;

  if (fuelGallons >= fuelUsed)
  {
    fuelGallons = fuelGallons - fuelUsed;
    totalMiles = totalMiles+distance;
  }
  else
  cout << "\t\tWE ARE RUNNING ON FUMES!\n";
}
//Dont forget there are two ways to code a constructor in cpp or h file!
//HybridCar::HybridCar(double _fuelGallons) : Car(_fuelGallons) //dont forget the constructor!!!
//This is included in the h file!
void HybridCar::drive(double speedMPH, double timeH)
{
  double mpg = 0.0;/// miles/mpg to
  if(speedMPH <= 45)
  {
    mpg = 55.0;
  }
  else if ( speedMPH == 55)
  {
    mpg = 46.0;
  }
  else if (speedMPH == 65)
  {mpg = 38;}
  else
  {
  mpg = 33.0;
  }

  double distance = speedMPH * timeH;
  double fuelUsed = distance / mpg;

  if (fuelGallons >= fuelUsed)
  {
    fuelGallons = fuelGallons - fuelUsed;
    totalMiles = totalMiles+distance;
  }
  else
  cout << "\t\tWE ARE RUNNING ON FUMES!\n";
}
/*
void ElectricCar::drive(double speedMPH, double timeH)
{

  double distance = 0.0;
  distance = speedMPH * timeH
  double fuelUsed = distance / speedMPH;
  if (fuelGallons >= fuelUsed)
  {
    fuelGallons = fuelGallons - fuelUsed;
    totalMiles = totalMiles+distance;
  }
  else
  cout << "WE NEED TO RECHARGE!\n";
}
*/
void Track::driveCars()
{
//cout << "We made it here 97! cars.size() == " << cars.size();//Range Error faults after 1st iteration of the following for loop!
  for(size_t i = 0; i < cars.size(); i++) //loop to perform calculations on each type of car
  {
    cout << "Car #: " << i+1 //make an enum type to display the name
    << " Distance traveled: " << cars[i] -> getTotalMiles()
    << " Fuel left: " << cars[i] -> getFuelGallons()
    << endl;
//cout << "We made it here 104!\n"; //range error!
    cars[i] -> drive(30,1.0); //first parameter was 30 changed to 45!
//cout << "We made it here 106!\n"; //range error!
//vector<Car*> cars was already declared!
   }
}

/*
previously declared in hfile! Dont orget!
void Track::attach(Car& c)
{

}
*/
