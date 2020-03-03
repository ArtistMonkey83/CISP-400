//#include "std_lib_facilities.h"
#include "Points.h"

//sing namespace Points;

int main ()
{
  Point points;
  Point p;
  vector<Point> original_points, processed_points;

  //cout << "test";

  for ( unsigned int i = 0; i < 7; i++)
  {
    cout << "(x,y):";
    cin >> points;
    original_points.push_back(points);


  }


  for ( unsigned int i = 0; i < 7; i++) //orginnial_points.size()?
  {
    cout <<original_points[i]<< endl;

  }


  ofstream ofs;
  ofs.open("mydata.txt");

  if (!ofs) error("failed to open mydata.txt");
  for(size_t i = 0; i < original_points.size(); i++)
  {
    ofs << original_points[i]<<endl;
  }

  ofs.close();

  ifstream ist;
  ist.open("mydata.txt");
  if (!ist) error("Could not open file mydata.txt");

  while(ist >> p)
  {processed_points.push_back(p);}
  //ist.close();

  ofs << original_points;

  cout << "Data from file:"<< endl;
  //for(unsigned int i =0; i<processed_points.size(); i++)

  for (size_t i = 0; i < processed_points.size(); i++)
  {cout << processed_points[i] << endl;}

  cout<< "Original data:"<< endl;
  for(size_t i = 0; i < original_points.size(); i++)
  {
    cout << original_points[i] << endl;
  }

  if (original_points.size() != processed_points.size())
  cout << "Somthing wrong!" << endl;

  //if(original_points == processed_points)
  else {cout << "Vectors equal!" << endl;}

  return 0;
}
