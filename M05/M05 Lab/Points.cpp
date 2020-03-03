#include "Points.h"
#include"std_lib_facilities.h
//namespace Points
//{
///Output in the format (x,y), no newline
ostream& operator<<(ostream& os, const Point& p)
{
  //for(Point p: points) // or while(!eof())?
  //{
    //os << "(x,y):\n"; maybe not here
    os << '('<< p.x<<','<< p.y<<')';
    return os;
  //}
}

///Input in the form (x,y)
///if is fails (!is), return is.  This is necessary for loops later on.
istream& operator>>(istream& is, Point& p)
{
  //int x, y;
  char c1,c2,c3;

  is >> c1 >> p.x >> c2 >> p.y >> c3;
  if(!is) return is;

  if(c1 != '(' || c2 != ',' || c3 != ')')
  {is.unget(); is.clear(ios_base::failbit); return is;} // set fail bit format is wrong
  return is;
  //p.x = x;
  //p.y = y;  //do i need push_back here? temps.push_back(p({x,y});



  /*if(c1 != '(' || c2 != ',' || c3 != ')')
  {is.clear(ios_base::failbit)} // set fail bit format is wrong
  while (is)
  {p.push_back(x); p.push_back(y);}*/
}

///true if the (x,y) values match
bool operator==(const Point& p1, const Point& p2)
{
  return p1.x == p2.x && p1.y == p2.y;
  //else return false; if this is implemented then the != will need to always return true
}

bool operator!=(const Point& p1, const Point& p2)
{
  return (!(p1==p2));
}

///Output a vector of points
///Call the << operator for a Point (above) for each point in the vector
///Separate by newlines
ostream& operator<<(ostream& os, const vector<Point> & points)
{
  for(size_t i =0; i<points.size();i++) // or while(!eof())?
  {
    //os << "(x,y):\n";
    os << '('<< points[i].x<<','<< points[i].y<<')';

  }
  return os;
}
//}
