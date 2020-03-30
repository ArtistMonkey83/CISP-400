#include "Simple_window.h"
//functions to graph
double one(double x) { return 1; } 		// y==1 constant
double slope(double x) { return x/2; }		// y==x/2 linear
double square(double x) { return x*x; } 	// y==x*x quadratic

// You can combine functions (e.g., by addition):
double sloping_cos(double x) { return cos(x)+slope(x); }

///this return value should be unsigned long long or double
int fac(int n) { return n <= 1 ? 1 : n * fac(n - 1);}  // factorial

double term(double x, int n) {return pow(x,n)/fac(n);}	// xn/n!

int expN_number_of_terms = 6;	// nasty sneaky argument to expN how many terms to use in Taylor series
                              //end of chapter proposes better ways to implement it
double expN(double x)	// sum of n terms of Taylor series for ex
{
	double sum = 0;
	for (int i = 0; i<expN_number_of_terms; ++i) sum+=term(x,i);
	return sum;
}

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

  Text ts(Point(100,y_orig-30),"one");    //100 to the right and a little (-)up from orgin
  Text ts2(Point(100,y_orig+y_orig/2-10),"x/2"); //halfway down from the y_origin/2 is a quarter down the screen so half way down  and up a little
  Text ts3(Point(x_orig-90,20),"x*x");    // 20 pixels from the top downward a little left of the middle in x's

  win0.attach(ts);       //attach() just takes shape pointers!! so must be shapes!
  win0.attach(ts2);
  win0.attach(ts3);

  /*
      Parameters: mapping between pixels and cartesian corrdinates
      enum to denote vertical or horizontal Axis::x/y, sideways or vertical?
      Starting point of the axis Point(20,y_orig) starting point
      Length of the axis in pixels how long we want in pixels xlength 400 and x_scale = 40 we get 10 notches!
      Number of notches to create how many notches we want
      Label to let us know what value a notch represents
  */
  Axis x(Axis::x, Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
  Axis y(Axis::y, Point(x_orig,ylength+20), ylength, ylength/y_scale, "one notch == 1");

  win0.attach(x);
  win0.attach(y);

  x.set_color(Color::red);
  y.set_color(Color::red);

  Function s4(cos,-10,11,orig,400,20,20);
  s4.set_color(Color::blue);
  Function s5(sloping_cos,-10,11,orig,400,20,20);

  win0.attach(s4);
  win0.attach(s5);

  win0.wait_for_button( );
  //win0.close();

  Simple_window win(Point(100,100),xmax,ymax,"Test a new window");
  // the real exponential :
  Function real_exp(exp,r_min,r_max,orig,200,x_scale,y_scale);
  real_exp.set_color(Color::blue);
  win.attach(real_exp);

  win.attach(x);
  win.attach(y);
  x.set_color(Color::red);
  y.set_color(Color::red);

  win.wait_for_button( );

  for (int n = 0; n<50; ++n)
  {
	ostringstream ss;                       //use this like a file
	ss << "exp approximation; n==" << n ;  //feeding string in to ostringstream with n as how many terms in Taylor series
	win.set_label(ss.str().c_str());
	expN_number_of_terms = n;	//nasty sneaky argument to expN

	// next approximation:
	Function e(expN,r_min,r_max,orig,200,x_scale,y_scale); //because of the data type we will tweak out around 18factorial

	win.attach(e);
	win.wait_for_button();	// give the user time to look
	win.detach(e);
  }

/*
struct Axis : Shape {
	enum Orientation { x, y, z };            //scoped enum we dint use z!
	Axis(Orientation d, Point xy, int length,
		int number_of_notches=0,	             // default: no notches
		string label = ""			                // default : no label
		);
	void draw_lines() const;               //override draw_lines()
	void move(int dx, int dy);             //we want to override move because
                                        //to move axis AND labels and notches!
	void set_color(Color);	// in case we want to change the color of all parts at once
	// line stored in Shape
	// orientation not stored (can be deduced from line)
	Text label;
	Lines notches;
};
///////////constructor that constructs label at (0,0) with what ever string came in to constructor
Axis::Axis(Orientation d, Point xy, int length, int n, string lab)
	:label(Point(0,0),lab)
{
	if (length<0) error("bad axis length");
	switch (d){
	case Axis::x:  //this switches between x,y,or z depending
	{	Shape::add(xy);			// axis line begin
		Shape::add(Point(xy.x+length,xy.y));	// axis line end the parent connects dots and makes a smooth line
		if (1<n) {                    //as long as there is more then one notch draw them
			int dist = length/n;       //the notches are built here in the child class this is how far apart the notches will be
			int x = xy.x+dist;         //starting point plus distance of pixels
			for (int i = 0; i<n; ++i) {  //loop through how many notches we want
				notches.add(Point(x,xy.y),Point(x,xy.y-5)); //add the starting point, right end point is starting plus length
				x += dist;                                  //5 pixel vertical notch, then bump x to next notch
			}
		}
		// label under the line
		label.move(xy.x + length/3,xy.y+20);
		break;
	}
	// …
}
//////////////
void Axis::draw_lines() const
{                       //adding to parents functionality!
	Shape::draw_lines();	// the line
	notches.draw_lines();	// the notches may have a different color from the line
	label.draw();        	// the label may have a different color from the line
}
void Axis::move(int dx, int dy)
{
	Shape::move(dx,dy);	// the line
	notches.move(dx,dy);
	label.move(dx,dy);
}
void Axis::set_color(Color c)     //overriding but not polymorphing
{
	Shape::set_color(c);
	notches.set_color(c);
	label.set_color(c);
}
*/
}
