#ifndef CAR_H
#define CAR_H //DONT FORGET!!

#include "std_lib_facilities.h"
/*
• Car
    ◦ Create a class named Car with the following attributes:
      #totalMiles : double
      #fuelGallons : double

      #Car(_fuelGallons : double)
      +getTotalMIles() const : double
      +getFuelGallons() const : double
      +drive(speedMph : double, timeH : double) : virrtual void =0
*/
class Car
{
  protected:
    double totalMiles = 0.0,
           fuelGallons;
    Car(double _fuelGallons){fuelGallons = _fuelGallons;} // constructor {to set value of variable!}
  public:
    double getTotalMiles() const {return totalMiles;}
    double getFuelGallons() const {return fuelGallons;}
    virtual void drive(double speedMPH, double timeH)  = 0; // do I need const here? NO you dont!!
};

/*
• Gasoline and Hybrid
    ◦ Create two classes, both of which inherit from Car, with the following attributes:

      GasolineCar :Car
      +GasolineCar(_fuelGallons: double)
      +drive(speedMph : double, timeH : double)override : virtual void

      HybridCar : Car
      +GasolineCar(_fuelGallons : double)
      +drive(speedMph : double, timeH : double)override : virtual void


    ◦ For the constructor, just pass the _fuelGallons argument to the parent constructor.
    ◦ For drive, do the following:
        ▪ Calculate the miles per gallon (mpg) using the following table from https://afdc.energy.gov/data/10312.
         Note:  Your function will be different depending on which child class you are in.

        ▪ Calculate the distance (d = vt)
        ▪ Calculate the fuel used (d / mpg)
        ▪ If(fuelGallons >= fuelUsed)
            • Subtract fuelUsed from fuelGallons
            • Add distance to totalMiles
        ▪ Else output "Out of fuel!"
*/
class GasolineCar : public Car
{
  public:
    GasolineCar(double _fuelGallons) : Car(_fuelGallons){}; //Here you are calling the parent constructor with no initialized variables
    virtual void drive(double speedMPH, double timeH) override;
};

class HybridCar : public Car
{
  public:
    HybridCar(double _fuelGallons) : Car(_fuelGallons){};
    virtual void drive(double speedMPH, double timeH) override;
};
/*
class ElectricCar : public Car
{
  public:
    ElectricCar(double _fuelGallons);
    virtual void drive(double speedMPH, double timeH) override;
};
*/


/*
• Track
    ◦ Create class Track with the following specifications:

    ◦ attach pushes the address of the given Car& to the back of the vector
        ▪ Use the & operator to get the address of a variable (&c)
    ◦ driveCars
        ▪ Loop through each Car*
            • Use the -> operator to access members of a pointer
            • Output the car number (index), distance traveled and fuel remaining
            • Call drive with arguments 30 mph and 1.0 miles (same for each car)

*/

class Track
{
  private:
    vector<Car*> cars; //putting this inside our driveCars() will over shadow this declaration!
  public:
    void driveCars(); //outputs text and calculate miles able to drive!
    void attach(Car& c){cars.push_back(&c);} //Dont Forget!!Similar to M05-7 assignment with win.attach() FLTK function!
};                                          // is cars.push_backworking?


#endif //CAR_H inlcuded Dont forget!
