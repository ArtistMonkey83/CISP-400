#include "Topograph.h"
///**************Part 1********************************
///Constructor.  Open a ArcGIS ASCII Grid file
///read the header to assign height and width
///resize v and read elevation data
Topograph::Topograph(string fileName)
{
  ifstream ifs{"fileName"};
  if(!ifs) error("Can't open file",fileName);

  string width = "ncols",
         height = "nrows",
         search4String = "";
  int    _width, _height;

  ifs >> search4String;
  if(search4String ==  width) {cin >> _width; width = _width;}

  ifs >> search4String;
  if(search4String == height) {cin >> _height; height = _height;}
  //second try ignore six things to get the read position to data
  ifs >> search4String >> search4String >> search4String >> search4String >> search4String >> search4String;

  //vector<vector<int>>  v
  while(true)
  {
    for(size_t i=0; i<v.size(); i++)
    {
      for (size_t j = 0; j<v.size(); j++)
      {
        int tempData;
        ifs >> tempData;
        if(ifs.eof()) break;
       v.push_back(vector<int>(tempData));
      } //v.at(i).at(j) would work also!
    }
  }
}

//int Topograph::getHeight(){return height;}
//int Topograph::getWidth(){return width;}

///find min and max elevation values
///call mapRange to convert each elevation to grayscale
///set each bmp(i,j) to its grayscale value
void Topograph::drawMap(Bmp& bmp)
{

  size_t countRow,
         countCols;
  int valueToCompute;

  for(countRow = 0; countRow < v.size(); countRow++)
  {
      for(countCols = 0; countCols < v.size(); countCols++)
    {
      valueToCompute = v.at(countRow).at(countCols); //v[0][0] this is faster

      bmp = mapRange(valueToCompute,min,max,255,0);
    }
  }

}

///**************Part 2********************************
///Draw one greedy path
///call moveForward to advance (i,j)
///set each bmp(i,j) to color
///returns the total sum of the elevation change
//int Topograph::drawGreedyPath(Bmp& bmp, int startingRow, rgb color)
//{

//}

///call drawGreedyPath for each startingRow, color red
///store the index of the path with lowest elevation change
///call drawGreedyPath for the lowest index, color blue
//void Topograph::drawBestPath(Bmp& bmp)
//{

//}
///****************************************************


///**************Part 1********************************
void Topograph::findMin()
{
  int lowest = v.at(0).at(0); //v[0][0] this is faster
  for(size_t countRow = 1; countRow < v.size(); countRow++)
  {
    for(size_t countCols = 1; countCols < v.size(); countCols++)
    {
      if(v.at(countRow).at(countCols) < lowest)
      {lowest = v.at(countRow).at(countCols);} //v[countRow][countCols]  would work also
    }
  }

  min = lowest;
}
void Topograph::findMax()
{
  int highest = v.at(0).at(0); //v[0][0] is faster
  for(size_t countRow = 1; countRow < v.size(); countRow++)
  {
    for(size_t countCols = 1; countCols < v.size(); countCols++)
    {
      if(v.at(countRow).at(countCols) > highest)
      {highest= v.at(countRow).at(countCols);}
    }
  }

  max = highest; //scope resolution operator for Topograph links this to proper private member of the class.
}
///scale n from [fromLow:fromHigh] to [toLow:toHigh]
/* y = mx +c
  m = slope of the line the ratio of range2/ range1
  c the y intercept of the line the difference between where range 2 and range 1 start, multiplied by the slope
  y dependent variable
  x independent variable
   var m = (y2-y1)/(x2-x1)
   var c = y1 -m *x1
   return m* x+c
*/
//a= fromLow b = fromHigh c = toLow d = toHigh x = n
//[((x-a)/(b-a)) * (d-c)] + c

int Topograph::mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh)
{
  /*int mappedValue = ((((n-fromLow)/(fromHigh-fromLow))) * (toHigh - toLow)) + toLow;
  */

  int fromArray = (n-fromLow)/(fromHigh-fromLow),
      toRange = toHigh - toLow,
      mappedValue = (fromArray * toRange) + toLow;
  return mappedValue;
}
