///Copyright Ryan Hermle.  Feb. 20, 2018.  All rights reserved.

#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include "../std_lib_facilities.h"

///Look up "Bitmap file header" and "Windows BITMAPINFOHEADER" for specs
//24 bits per pixel is standard go to wikipedia
struct BitmapInfoHeader
{   //datatable from wikipedia

    ///Bitmap file header
    short headerType;
    int fileSize;
    short reserved1, reserved2;
    int offset;

    ///Windows BITMAPINFOHEADER
    int headerSize, width, height;
    short colorPlanes, bitsPerPixel;
    int compressionMethod, imageSize, horizRes,
    vertRes, numColors, numImportantColors;
};

struct rgb
{
    unsigned char r,g,b;
};

class Bmp
{
    public:
        ///allocate pixel vector
        Bmp(int _height, int _width);
        ///default constructor, does nothing
        Bmp(){}

        void write(string fileName); ///generate header, write pixels and header to file based on array
        void read(string fileName);  ///read header and pixels from file.  Reallocates pixel vector

        int getHeight(){return height;} //should contain const
        int getWidth(){return width;}

        ///pixel write
        rgb& operator()(int i, int j)
        {
            if(i < 0 || i >= height || j < 0 || j > width) error("Pixel indices out of bounds");
            return pixels[i][j]; //2d vector that we want to access
        }
        ///pixel read
        const rgb& operator()(int i, int j) const
        {
            if(i < 0 || i >= height || j < 0 || j > width) error("Pixel indices out of bounds");
            return pixels[i][j];
        }

    private:
        ///helper member functions
        void readHeader(istream&);  ///reads the header from a .bmp file based on struct
        void writeHeader(ostream&); ///writes the header to a .bmp file
        void readPixels(istream&);  ///read pixel data from .bmp.  Assumes header is already read.
        void writePixels(ostream&); ///write pixel data to .bmp.  Assumes header is already read.

        ///creates a header based on the pixel data.  Assumes pixels already loaded.
        ///called by setPixels so the header matches the pixels.
        void createHeader();
//create header write a header and create file when we construct
        void printHeader();///output a header for debugging

        ///member variables
        BitmapInfoHeader header;
        vector<vector<rgb>> pixels;  ///2D vector of pixels resizes depening on constructor
        int height;
        int width;
        ///Extra bytes at the end of each row to make the width divisible by 4
        int rowPadding; //to make sure every row is a multiple of four bytes this will add bytes to make it a multiple of four
};


#endif // BMP_H_INCLUDED
