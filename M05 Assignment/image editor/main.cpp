///Copyright Ryan Hermle.  Feb. 20, 2018.  All rights reserved.

#include "Bmp.h"

const string VIEWING_APP = "eog ";

int main()
{
    string fileName1 = "snowboarding.bmp";
    string fileName2 = "snowboarding2.bmp";

    Bmp bmp;  //default constructor no pixels
    bmp.read(fileName1); //reads bmp
                        //array of rgb values
                        //reads into a 2d vectors


    ///Change white to pink
    for(int i = 0; i < bmp.getHeight(); i++)
    {
        for(int j = 0; j < bmp.getWidth(); j++)
        {
            if(bmp(i,j).b > 200 && bmp(i,j).r > 200 && bmp(i,j).g > 200)  //values close to white
            {
                bmp(i,j).r = 255;
                bmp(i,j).g = 128;
               bmp(i,j).b = 128;
            }
        }
    }

    bmp.write(fileName2); //writing from array in bmp to fileName2

    system((VIEWING_APP + fileName1 + " &").c_str()); ///system call to open the image file for viewing
    system((VIEWING_APP + fileName2 + " &").c_str()); //& opens a new window  system() enables commandline syntax

    ///create a 100x100 bmp with random pixel colors
    Bmp bmp2(100,100);  //constructor with set width hieght
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            bmp2(i,j).r = rand() % 256;
            bmp2(i,j).g = rand() % 256;
            bmp2(i,j).b = rand() % 256;
        }
    }
    string fileName3 = "out.bmp";
    bmp2.write(fileName3);
    system((VIEWING_APP + fileName3 + " &").c_str());

    return 0;
}
