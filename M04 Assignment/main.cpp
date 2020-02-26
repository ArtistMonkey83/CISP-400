#include "Matrices.h"
#include "std_lib_facilities.h"

using namespace Matrices;

 Matrix populateMatrix(vector<double> a, int r, int c)   //populating a maxtrix with r rows and c columns
{
   if((int)a.size() != r*c) error("Maxtrix must have the correct amount of rows and columns!");
   Matrix m(r,c);      //constructing a matrix
   int element = 0;
  for(int i = 0; i < r; i++)
   {
     for(int j = 0; j < c ; j++) {m(i,j)=a[element++];}
   }
   return m;
 }

 int main()
 {
   try
   {
     Matrix a = populateMatrix({0,-1,1,0}, 2, 2);
     Matrix b = populateMatrix({1,0.866825,1,0.5,0,0.5,1,0.866025}, 2,4);

     Matrix c = populateMatrix(vector<double>(4,0), 2, 2);
     //Matrix c = b + b;
     c = (b + b);
     cout << "a:" << a;
     cout << "b:" << b;
     cout << "c = b + b:" << c;
     c = a * b;
     cout << "c = a * b:" << c;

     return 0;
   }
   catch(...)
   {
     cout << "Exception caught" << endl;
     return 1;
   }
   keep_window_open();


//hand populating matrices option 2

/*
  Matrix a, b;

  a{2,2};
  b{2,4};

  a(0,0) = 0;
  a(0,1) = -1;
  a(1,0) = 1;
  a(1,1) = 0;

  b(0,0) = 1;
  b(0,1) = 0;
  b(1,0) = 0.866025;
  b(1,1) = 0.5;
  b(2,0) = 1;
  b(2,1) = 1;
  b(3,0) = 0.5;
  b(3,1) = 0.866025;

*/
}
