#include "Matrices.h"
//#include "../std_lib_facilities.h"

namespace Matrices
{
Matrix::Matrix(int _rows, int _cols)
{
  rows = _rows;
  cols = _cols;
  for(int i = 0; i<_rows; i++)
  {a.push_back(vector<double> (_cols,0));}
}
//Add each corresponding element construct a local matrix to store
//the result and return it using c = a + b
//if a and b do not have the same number of rows and colomns throw
//an error
Matrix operator+(const Matrix& a, const Matrix& b)
{
    if(!(a.getRows()== b.getRows())) {error("Matrices must have equal number of rows!\n");}
    if(!(a.getCols()== b.getCols())) {error("Matrices must have equal number of columns!\n");}

    Matrix sum(a.getRows(),a.getCols());

    for(int r =0; r < a.getRows(); r++)
    {
      for(int c =0; c < a.getCols(); c++)
      {sum(r,c)= a(r,c) + b(r,c);}
    }
    return sum;

}


//Perform matrix multiplication for a matrix a with row i and column j
//and a matrix b with row j and column k the product c of two
//matrices is defined as c(i,k) = a(i,0)*b(o,k) + a(i,2)*b(2,k)+ ...
//elements at row i of are are mulitipled and summed with elements
// in columnn k of b and store the resulting sum in element c(i,k)
//This can be done with a triple nested for loop
//outermost look control k and the collumn index for b
//the next loop control i, the row for a
//the innermost loop will control j, with will determine which column to use from a and with row ot use from b
//create a running sum when the j loops is finished store in c(i,k)
//if the number of columns and rows in a and b dont match throw and error
//construct a local matrix to store the result and return it.
Matrix operator*(const Matrix& a, const Matrix& b)
{
  if(a.getCols()!=b.getRows()) error("Matrices don't match!");
  Matrix product(a.getRows(),b.getCols());
  for(int r = 0 ; r < a.getRows() ; r++)
  {
    for(int c = 0 ; c < b.getCols() ; c++)
    {
      for(int k = 0 ; k < b.getRows() ; k++)
      {product(r,c)+= a(r,k)*b(k,c);}
    }
  }
  return product;
}


//if the rows and columns are not equal return false
//if any element (i,j) doesnt match return false otherwise return true
bool operator==(const Matrix& a, const Matrix& b)
{
  if(a.getCols() != b.getCols() || a.getRows() != b.getRows()  ) return false;
  bool isEqual = true;
  for(int i = 0 ; i < a.getRows() && isEqual ; i++){
    for(int j = 0 ; j < a.getCols() && isEqual ; j++){
      isEqual = (a(i,j) == b(i,j));
    }
  }
    return isEqual;
}



//opposite of ==operator
  bool operator!=(const Matrix& a, const Matrix& b)
  {
    return !(a==b);
  }


//Output operator will out put matrices in the format with columns separated by ' ' and rows by '\n' you can specify the width of your columns useing setw from <iomanip>
  ostream& operator<<(ostream& os, const Matrix& a)
  {
    os <<endl;
    for(int i = 0; i<a.getRows(); i++)
    {
      //os <<endl;
      for(int j=0; j<a.getCols(); j++)
      {
        os << setw(10)<<setprecision(7)<<a(i,j)<< " ";
      //  os << endl; //this1
      }
      os << endl; //this
    }
  //os<<endl;
    return os;
  }

///push back x into the first row and y into the second row
///add one to cols member variable to keep track
void addCoordinate(double x, double y)
{
    cols ++;
    //a.resize(rows); doesnt do anyting
    for (int i =0; i < a.size(); i++)
    {a[i].resize(cols);}

  //  a[0][cols-1]=x;
  //  a[1][cols-1]=y;

    a[0].push_back(x);
    a[1].push_back(y);
}

///2D rotation matrix
///usage:  A = R * A rotates A theta radians counter-clockwise
///Call the parent constructor to create a 2x2 matrix
///Then assign each element as follows:
/*
cos(theta)  -sin(theta)
sin(theta)   cos(theta)
*/
///theta represents the angle of rotation in radians, counter-clockwise
RotationMatrix::RotationMatrix (double theta) : Matrix(2,2)
{
  a[0][0]= cos(theta);
  a[0][1]= -sin(theta);
  a[1][0]= sin(theta);
  a[1][1]= cos(theta);
}

///2D scaling matrix
///usage:  A = S * A expands or contracts A by the specified scaling factor
///Call the parent constructor to create a 2x2 matrix
///Then assign each element as follows:
/*
scale   0
0       scale
*/
///scale represents the size multiplier
ScalingMatrix::ScalingMatrix(double scale) : Matrix (2,2)
{
  a[0][0]= scale;
  a[0][1]= 0;
  a[1][0]= 0;
  a[1][1]= scale;
}

///2D Translation matrix
///usage:  A = T + A will shift all coordinates of A by (xShift, yShift)
///Call the parent constructor to create a 2xn matrix
///Then assign each element as follows:
/*
xShift  xShift  xShift  ...
yShift  yShift  yShift  ...
*/
///paramaters are xShift, yShift, and nCols
///nCols represents the number of columns in the matrix
///where each column contains one (x,y) coordinate pair
TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols)
{
  int c;
    for(c = 0; c < nCols-1; ++c)
    {
      a[0][c]= xShift;
      a[1][c]= yShift;
    }
}

}
