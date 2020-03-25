#include "PolygonMatrix.h"

///used to map from pixels to Cartesian coordinates and back
//int mapRange(int , int fromLow, int fromHigh, int toLow, int toHigh)
//{return toLow+((double)n-fromLow)*(toHigh-toLow)/(fromHigh-fromLow);}
double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
{
  return toLow+((double)n-fromLow)*(toHigh-toLow)/(fromHigh-fromLow);
}
///construct pointMatrix with 2 rows and 0 cols
///store xPixels and yPixels for range mapping
PolygonMatrix::PolygonMatrix(int _xPixels, int _yPixels) Matrix pointMatrix(2,0) //Fl::w() Fl::h()??
{
  PolygonMatrix.xPixels = _xPixels;
  PolygonMatrix.yPixels = _yPixels;

}

///add a pixel vertex to the polygon
///call the parent add function with Point p
///use mapRange to map p.x and p.y to Cartesian coordinates
///use addCoordinate to add the mapped x and y values to pointMatrix
void PolygonMatrix::add(Point p) // passed argument is a pixel vertex from main mapped to Cartesian using mapRange
{
  //([0:xPixels],[yPixels :0])  <==> ([-xPixels / 2 : xPixels/2], [-yPixels/ 2 : yPixels/2])
  //  from PolygonMatrix.h
  //double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh);

  double pointX = mapRange(p.x,0,xPixels,(-xPixels/2), (xPixels/2));
  double pointY = mapRange(p.y,yPixels,0,(-yPixels/2),(yPixels/2)); //dont flip the xs
  //

  pointMatrix.addCoordinate(pointX,pointY); //what value represents the x and y?
                                            // p.y and p.x ???

  Polygon::add(p);

}

///rotate polygon by theta radians counter-clockwise
///construct a RotationMatrix R, mulitply it by pointMatrix
///then call updatePixels
void PolygonMatrix::rotate(double theta)
{
  RotationMatrix r(theta);
  pointMatrix = r * pointMatrix;

  pointMatrix.updatePixels();
}

///Scale the size of the polygon by factor c
///construct a ScalingMatrix S, multiply it by pointMatrix
///then call updatePixels
void PolygonMatrix::scale(double c)
{
  //ScalingMatrix::ScalingMatrix S() : Matrix (2,2){c,0,0,c}; in the class
  ScalingMatrix s(c);
  pointMatrix = s * pointMatrix;

  pointMatrix.updatePixels();
}

///shift the polygon by (xShift, yShift) coordinates
///construct a TranslationMatrix T, add it to pointMatrix
///then call updatePixels
void PolygonMatrix::translate(double xShift, double yShift)
{
  //TranslationMatrix::TranslationMatrix T() : Matrix(2,n) {} //n is total number of stored points
  TranslationMatrix t(xShift,yShift,pointMatrix.getCols()); //(xshift, y shift,pointMatrix.getCols());
  pointMatrix = t + pointMatrix;

  pointMatrix.updatePixels();
}

///Const getter for the unit tester to view the internal matrix
//const Matrix& getPointMatrix() const{return pointMatrix;}

///Loop through each column of point matrix
///map each coordinate to pixels
///call Shape::set_point to update each pixel
void PolygonMatrix::updatePixels()
{
  Point temp;

  for(int i = 0; i < pointMatrix.getCols(); i++)//loop through each column of pointMatrix
  {
    //double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh);
    //map cartesian coordinates to a Point containing x and y pixel values
    //going from cartesian to pixel values

    temp.x = mapRange(pointMatrix[0,i],(-xPixels/2),(xPixels/2),0,xPixels);
    temp.y = mapRange(pointMatrix[1,i],(yPixels/2),(-yPixels/2),yPixels,0);


    Polygon::set_point(temp); //updating point in the graphics lib for later drawing ????Shape::set_point(temp)????
  }

}




/*
Star::Star (inw, int h) : PolygonMatrix(w,h){}
int centerX = w /2;
int centerY = h/2;
addpoint()
set_fill_color()
*/
