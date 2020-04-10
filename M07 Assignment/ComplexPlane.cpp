///helper functions to be unit tested
///map from pixels to complex plane
double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh);
///write rgb values into one dimensional FLTK output buffer
void writePixel(unsigned char* buf, int xPixels, int row, int col, unsigned char r, unsigned char g, unsigned char b);
///count the number of Mandelbrot iterations for a given point on the complex plane, used to determine pixel color
int countIterations(double re, double im, int maxIterations);
