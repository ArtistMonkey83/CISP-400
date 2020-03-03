#include "std_lib_facilities.h"
#include "Points.h"

int main ()
{
  Point points, p;
  vector<Point> original_points, processed_points;

  for ( unsigned int i = 0; i < 7; i++)
  {
    cin >> points;
    original_points.push_back(points);
    cout << "(x,y)" << endl;

  }


  for ( unsigned int i = 0; i < 7; i++)
  {
    cout <<original_points[i]<< endl;

  }


  ofstream ofs("mydata.txt");
  if (!ofs) error("failed to open mydata.txt");
  for(int i = 0; i < 7; i++)
  {
    ofs << original_points[i]<<endl;
  }

  ofs.close();

  ifstream ist ("mydata.txt");
  if (!ist) error("Could not open file mydata.txt");

  while(ist >> p)
  {processed_points.push_back(p);}

  ofs << original_points;

  cout << "Data from file:"<<endl;
  //for(unsigned int i =0; i<processed_points.size(); i++)

  for (unsigned int i = 0; i < processed_points.size(); i++)
  {cout << processed_points[i] << endl;}

  cout<< "Original data:"<< endl;
  for(unsigned int i=0;i<processed_points.size(); i++)
  {
    cout << original_points[i] << endl;
  }

  if (original_points.size()!= processed_points.size())
  cout << "Somthing wrong!" << endl;

  if(original_points == processed_points)
  {cout << "Vectors equal!" << endl;}

  return 0;
}
