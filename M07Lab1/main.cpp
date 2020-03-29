
#include "Simple_window.h"
//functions to graph
double one(double x) { return 1; } 		// y==1 constant
double slope(double x) { return x/2; }		// y==x/2 linear
double square(double x) { return x*x; } 	// y==x*x quadratic

int main()
{                                                                  //positive is down for y values!!!
  Simple_window win0(Point(100,100),600,400,"Function graphing"); //(Point(100,100)... how far over and down


  const int xmax = win0.x_max();	// window size (600 by 400) grabs how many pixels wide
  const int ymax = win0.y_max();  //grabs how many pixels high from above constructor

  const int xlength = xmax-40;  //the length of our x and y axis will stop a little short of the edge
  const int ylength = ymax-40;

  const int x_orig = xmax/2;    //the origin which is a point in the middle
  const int y_orig = ymax/2;
  const Point orig(x_orig, y_orig); 	 // position of Cartesian (0,0) in window

  const int r_min = -10;		// range [-10:11) to graph
  const int r_max = 11;

  const int n_points = 400;	// number of points used in range how many dots to graph the more the smoother the curn

  const int x_scale = 20;		// scaling  factors
  const int y_scale = 20;

  // Choosing a center (0,0), scales, and number of points can be fiddly
  // The range usually comes from the definition of what you are doing
                                                                  //...,600,400 width and hieght of window in pixels
  Function s(one,          -10,11,   orig,   n_points,x_scale,y_scale);   //takes function we want to graph -10,11 left end point right end point
  Function s2(slope,     -10,11,   orig,   n_points,x_scale,y_scale);     //orig in pixels the center "where it starts!", n_points is resolution
  Function s3(square,  -10,11,   orig,   n_points,x_scale,y_scale);     //x_/y_scale how many pixels there are for each x and y

  win0.attach(s);       //attach() just takes shape pointers!! so fucntion s1, s2, s3 must be shapes!
  win0.attach(s2);
  win0.attach(s3);

  win0.wait_for_button( );
}
