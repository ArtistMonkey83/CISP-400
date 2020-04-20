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
#include "Point.h"
//#include "YoliesHeadnFoot.h
#include "std_lib_facilities.h"

/*
      ______                _   _               _____           _     _______
    |  ____|              | | (_)             |  __ \         | |   |__   __|
   | |__ _   _ _ __   ___| |_ _  ___  _ __   | |__) | __ ___ | |_ ___ | |_   _ _ __   ___  ___
  |  __| | | | '_ \ / __| __| |/ _ \| '_ \  |  ___/ '__/ _ \| __/ _ \| | | | | '_ \ / _ \/ __|
 | |  | |_| | | | | (__| |_| | (_) | | | | | |   | | | (_) | || (_) | | |_| | |_) |  __/\__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| |_|   |_|  \___/ \__\___/|_|\__, | .__/ \___||___/
                                                                       __/ | |
                                                                      |___/|_|
*/

void yoliesProgramHeader();
void yoliesProgramFooter();
void displayExplanation();

/*
     __  __       _         ______                _   _
    |  \/  |     (_)       |  ____|              | | (_)
   | \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
  | |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
 | |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/


int main ()
{
  try
  {
    yoliesProgramHeader();
    displayExplanation();
    int totalRows=3;

    //Open the file and read it into a vector of Points
    ifstream ifs{"coordinates.txt"}; //dont forget " " around file name!!
    if (!ifs) // which one is faster and more effecient? error("Problem opening file!\n");
      throw runtime_error("Opening and reading a file into a vector of Points!\n");
    //cout << " We made it here line 42!\n";
    vector<Point> extractedData;
    Point holdingData;

    while(ifs >> holdingData)
    {extractedData.push_back(holdingData);}
    //cout << " We made it here line 48!\n";
    ifs.close(); ///Dont forget to close the ifstream object!!

    //Declare a 2d vector of doubles with 3 rows and n columns, where n is the total number of Points already
    vector<double> v;
    vector<vector<double>> localCopyData;
    localCopyData.resize(totalRows, vector<double>(extractedData.size(),0));
     //cout << " We made it here line 55!\n";

    //void createMatrix(const vector<Point>& v1, vector<vector<double>>& v2);
    //Pass the two vectors into createMatrix
    //Output the matrix vector to a file named "coordinatesMatrix.txt" in the format shown above

    createMatrix(extractedData,localCopyData);
    ofstream ofs("YoliesCoordinatesMatrix.txt");
    //cout << " We made it here line 60!\n";
    cout << "\n\tBelow is the format you will find in YoliesCoordinatesMatrix.txt\n";
    for(int i = 0; i < totalRows; i ++)
    {
      for(size_t j = 0; j < extractedData.size(); j++)
      {
        ofs << localCopyData[i][j] << " ";
        cout << localCopyData[i][j] << " ";
      }
      ofs << endl;
      cout << endl;
    }
    //cout << " We made it here line 69!\n";
    ofs.close();      ///Don't forget to close ofstream object!

    yoliesProgramFooter();

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
/*
     ______                _   _
    |  ____|              | | (_)
   | |__ _   _ _ __   ___| |_ _  ___  _ __  ___
  |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |  | |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/

void yoliesProgramHeader()
{
  cout << "\n\n********************************* YOLIE REYES **********************************\n";
  cout << "********************************** Review Exam 2 *******************************\n";
  cout << "*********************************** 04-19-2020 *********************************\n";
  cout << "*********************************** CISP 400 ***********************************\n";
}


void yoliesProgramFooter()
{
  cout << "\n\t\t****** NAHUATL WORD OF THE DAY ******\n\n";
  cout << "\t\t****** Huitzilin (weet-see-leen) ******\n\n\n";
  cout << "English - Hummingbird: A small nectar-feeding tropical American bird that is able to hover and fly backward, typically having colorful iridescent plumage. In Nahuatl culture the goddess Xochiquetzal, patron of artists, is usually accompanied by hummingbirds.\n\n";
  cout << "Spanish - Colibrí: Un pequeño pájaro tropical que se alimenta de néctar y es capaz de flotar y volar hacia atrás, por lo general tiene un colorido plumaje iridiscente. En la cultura Náhuatl, la diosa Xochiquetzal, patrona de los artistas, suele ir acompañada de colibríes.\n\n";
  cout << "German - Kolibri: Ein kleiner amerikanischer Vogel, der Nektar füttert, der in der Lage ist, rückwärts zu schweben und zu fliegen, normalerweise mit einem bunt schillernden Gefieder. In Nahuatls Kultur wird die Göttin Xochiquetzal, Schutzpatronin der Künstler, in der Regel von Kolibris begleitet\n\n";
  cout << "Russian - Колибри: небольшая тропическая американская птица, питающаяся нектаром, способная парить и летать назад, обычно с ярким переливающимся оперением. В науатльской культуре богиня Шочикецаль, покровитель художников, обычно сопровождается колибри\n\n";
  cout << "French - Le colibri: Est un petit oiseau américain tropical qui se nourrit de nectar et qui est capable de planer et de voler en arrière, avec un plumage coloré et irisé. Dans la culture Nahuatl, la déesse Xochiquetzal, patronne des artistes, est généralement accompagnée de colibris\n\n";
  cout << "\n******************************** End of Program ********************************\n\n\n";
}

void displayExplanation()
{
cout << "\t\tThe purpose of this project is to \n\t\ttest my ability to input and output files.\n";

}
