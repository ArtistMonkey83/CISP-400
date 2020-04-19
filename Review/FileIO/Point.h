#ifndef POINT_H
#define POINT_H
#include "std_lib_facilities.h"

struct Point
{
/*
  double getX() const {return x;}
  double getY() const {return y;}
  double getZ() const {return z;}

  double setX(double _x);
  double setY(double _y);
  double setZ(double _z);

  private:
*/
  public:
    double x,
           y,
           z;
};

//Define an extraction operator >> to read a Point from an istream format is (x,y,z)
istream& operator>>(istream& is, Point& a); //the return type is istream& DONT FORGET!

//Define an insertion operator << to write a Point to an ostream as (x,y,z). *this is not unused
ostream& operator<<(ostream& os, const Point& a); //the return type is ostream& DONT FORGET!

//assume the size of v2 is already properly allocated, write v1 into v2 as
// x x x ...
// y y y ...
// z z z ...
void createMatrix(const vector<Point>& v1, vector<vector<double>>& v2);

//Open the file and read it into a vector of Points
//Declare a 2d vector of doubles with 3 rosw and n columns, where n is the total number of Points already
//Pass the two vectors into createMatrix
//Ooutput the matrix vector to a file named "coordinatesMatrix.txt" in the format shown above

#endif //POINT_H Included
