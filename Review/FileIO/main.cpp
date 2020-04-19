/*

File I/O
Assume that a file named "coordinates.txt" exists in your project directory.  Its content is as follows:

(x, y, z) (x, y, z) (x, y, z) …

Where x, y, and z represent doubles.  Assume the file has no formatting errors, you do not need to check.

    • Define a struct called Point that holds three doubles x, y, and z
    • Define an extraction operator >> to read a Point from an istream
    • Define an insertion operator << to write a Point to an ostream as (x, y, z).  *this is unused
    • void createMatrix(const vector<Point>& v1, vector<vector<double>>& v2)
        ◦ Assume the size of v2 is already properly allocated.  Write v1 into v2 as:
x x x …
y y y …
z z z …
    • main
        ◦ Open the file and read it into a vector of Points
        ◦ Declare a 2D vector of doubles with 3 rows and n columns, where n is the total number of Points read
        ◦ Pass the two vectors into createMatrix
        ◦ Output the matrix vector to a file named "coordinatesMatrix.txt" in the format shown above
*/





#include"Point.h"
#include "std_lib_facilities.h"

int main ()
{
  try
  {
    int totalRows=3;

    //Open the file and read it into a vector of Points
    ifstream ifs{"coordinates.txt"}; //dont forget " " around file name!!
    if (!ifs) error("Couldn't open file!\n");
      //throw runtime_error("Opening and reading a file into a vector of Points!\n");
cout << " We made it here line 42!\n";
    vector<Point> extractedData;
    Point holdingData;

    while(ifs >> holdingData)
    {extractedData.push_back(holdingData);}
cout << " We made it here line 48!\n";
    ifs.close(); ///Dont forget to close the ifstream object!!

    //Declare a 2d vector of doubles with 3 rows and n columns, where n is the total number of Points already
    vector<double> v;
    vector<vector<double>> localCopyData;
    localCopyData.resize(totalRows, vector<double>(extractedData.size(),0));
cout << " We made it here line 55!\n";
    //void createMatrix(const vector<Point>& v1, vector<vector<double>>& v2);

    createMatrix(extractedData,localCopyData);
    ofstream ofs("coordinatesMatrix.txt");
cout << " We made it here line 60!\n";
    for(int i = 0; i < totalRows; i ++)
    {
      for(size_t j = 0; j < extractedData.size(); j++)
      {
        ofs << localCopyData[i][j] << " ";
      }
      ofs << endl;
    }
    cout << " We made it here line 69!\n";
    ofs.close();      ///dont forget to close ofstream object
    // do we really need this? cout << "Done" << endl;
cout << " We made it here line 71!\n";
    //Pass the two vectors into createMatrix
    //Ooutput the matrix vector to a file named "coordinatesMatrix.txt" in the format shown above


    return 0;
  }
  catch (runtime_error& e)
  {
    cout << e.what() << endl;

    return 1;
  }
  keep_window_open();
}

//
