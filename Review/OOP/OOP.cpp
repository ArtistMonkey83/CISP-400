/*
Object Oriented Programming
    • For the following code, inline functions are okay, just denote what code is in the .h file and what is in the .cpp file.
    • Car
        ◦ Create a class named Car with the following attributes:
          #totalMiles : double
          #fuelGallons : double

          #Car(_fuelGallons : double)
          +getTotalMIles() const : double
          +getFuelGallons() const : double
          +drive(speedMph : double, timeH : double) : virrtual void =0

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
    • Track
        ◦ Create class Track with the following specifications:

        ◦ attach pushes the address of the given Car& to the back of the vector
            ▪ Use the & operator to get the address of a variable (&c)
        ◦ driveCars
            ▪ Loop through each Car*
                • Use the -> operator to access members of a pointer
                • Output the car number (index), distance traveled and fuel remaining
                • Call drive with arguments 30 mph and 1.0 miles (same for each car)
    • Main
        ◦ Construct a Track
        ◦ Construct 2 GasolineCars and 2 HybridCars
        ◦ Loop and call driveCars for each iteration.  Output the lap #
        ◦ Give the cars 14, 12, 14, and 12 gallon tanks, respectively, and 26 laps
*/
//Track : Car
//-cars : vector<Car*>
//+driveCars() : void
//+attach(c : Car&) : void
