#include"Point.h"

//set the private members x, y, z to a double
/*
double Point::setX(double _x)
{
  this-> x = _x;
}

double Point::setY(double _y)
{
  this-> y = _y;
}

double Point::setZ(double _z)
{
 this-> z = _z;
}

*/

//Define an extraction operator >> to read a Point from an istream format is (x,y,z)
istream& operator>>(istream& is, Point& a)
{
  //will hold the double values of the left hand side Point
  double _x,
         _y,
         _z;
  //will hold the ( , , ) characters of hte left hand side Point
  char ch1,
       ch2,
       ch3,
       ch4;

  //input stream to read a left hand side Point into the local variables
  is >> ch1 >>_x >> ch2 >> _y >> ch3 >>_z >> ch4;
  if (!is) return is;//{throw runtime_error("Problem reading the file!");}; //if there is something wrong with the istream exit function

  //checking the format of the corrdinate provided and returning out of the function
  if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
  {
    //cout << "Error reading the corrdinate!\n";
    is.unget();                        // Unget the character maybe calling function can use it
    is.clear(ios_base::failbit);      // Set fail bit format is wrong
    throw runtime_error("Format Error!");
    //return is;
  }


  //if we make it here then istream didn't have a problem and we can set the right hand side
  //Point& a members using public setter functions

  a.x = _x;
  a.y = _y;
  a.z = _z;

  /*
  /////First try////
  a.setX(_x);
  a.setY(_y);
  a.setZ(_z);
  */


  return is; //Don't forget to return the istream variable!!
}
//Define an insertion operator << to write a Point to an ostream as (x,y,z). *this is not unused
ostream& operator<<(ostream& os, const Point& a)
{
  ////First Try ////
  //os << '(' << a.getX() << ',' << a.getY() << ',' << a.getZ() << ')' << endl;

  os << '(' << a.x << ',' << a.y << ',' << a.z << ')' << endl;
  return os;
}
//assume the size of v2 is already properly allocated, write v1 into v2 as
// x x x ...
// y y y ...
// z z z ...
void createMatrix(const vector<Point>& v1, vector<vector<double>>& v2)
 {
  ///////First Try////////
  /*for(int row = 0; row < v2.size(); row++) // traverse the rows
  {
    for(int col = 0; row < v2.size(); col++)   // traverse the columns
    {
      v2[row][col].setX([v1[row][col].getX()); // set v2 member x to v1 member x
      v2[row][col].setY([v1[row][col].getY()); // set v2 member y to v1 member y
      v2[row][col].setZ([v1[row][col].getZ()); // set v2 member z to v1 member z
    }
  }
  */
  ///Second Try////////
  for(size_t col = 0; col < v1.size(); col++)   // traverse the columns
  {
    v2[0][col] = v1[col].x; // set v2 member x to v1 member x
    v2[1][col] = v1[col].y; // set v2 member y to v1 member y
    v2[2][col] = v1[col].z; // set v2 member z to v1 member z
  }
}
