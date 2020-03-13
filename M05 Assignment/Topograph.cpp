#include"Topograph.h"

Topograph::Topograph(string filename)
{
  ifstream ifs(filename);
  string temp;
  int cols,
      rows;

  ifs >> temp >> cols;
  ifs >> temp >> rows;
  height = rows;
  width = cols;

  //ignore whitespace in header file
  ifs.ignore();

  //skip next three lines
  getline(ifs,temp);
  getline(ifs,temp);
  getline(ifs,temp);
  v = vector<vector<int>> (height , vector<int>(width,0));

  for(int i = 0 ; i < height ; i++)
  {
    int j = 0;
    string input;
    getline(ifs, input);
    istringstream value(input);
    while(value>>v[i][j++]&&j<width);
  }
  findMin();
}


void Topograph::findMin()
{
    int minimum = v[0][0];
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ;j++)
        {
        if(v[i][j] < minimum) minimum = v[i][j];
        }
    }
    min = minimum;
}

void Topograph::findMax()
{
  int temp = v[0][0];
  for(int i = 0 ; i < height ; i++)
  {
    for(int j = 0 ; j < width ;j++)
    {
      if(v[i][j] > temp) temp = v[i][j];
    }
  }
  max = temp;
}

int Topograph::mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh)
{
  return toLow+((double)n-fromLow)*(toHigh-toLow)/(fromHigh-fromLow);
}

void Topograph::drawMap(Bmp& bmp)
{
  findMax();
  findMin();
  for(int i = 0 ; i < height ; i++)
  {
    for(int j = 0 ; j < width ;j++)
    {
      unsigned char y = (unsigned char)mapRange(v[i][j] , min , max , 0 , 255);
      bmp(i,j) = {y,y,y};
    }
  }

}

int Topograph::drawGreedyPath(Bmp& bmp, int startingRow, rgb color)
{
    int sum = 0,
        i = startingRow,
        j = 0;

    bmp(i,j) = color;
    while(j < width - 1)
    {
        int previous = v[i][j];
        moveForward(i,j);
        bmp(i,j) = color;
        sum += fabs(previous - v[i][j]);
    }
    return sum;
}

void Topograph::moveForward(int& i, int& j)
{
    int forward,
        forwardUp,
        forwardDown;

    if(i == 0)
        {
            forwardDown = fabs(v[i][j] - v[i+1][j+1]);
            forward = fabs(v[i][j] - v[i][j+1]);
            if(forward <= forwardDown) {j++;return;}
            i++;
            j++;
            return;
        }
    if(i == height - 1)
    {
        forward = fabs(v[i][j]-v[i][j+1]);
        forwardUp = fabs(v[i][j]-v[i-1][j+1]);
        if(forward <= forwardUp) {j++;return;}
        i--;
        j++;
        return;
    }

    forwardUp = fabs(v[i][j] - v[i-1][j+1]);
    forward = fabs(v[i][j] - v[i][j+1]);
    forwardDown = fabs(v[i][j] - v[i+1][j+1]);

    if(forwardDown <= forwardUp && forwardDown < forward) {i++; j++; return;}
    if(forwardUp < forward && forwardUp < forwardDown) { i--; j++; return;}
    if(forward <= forwardUp && forward <= forwardDown) {j++; return;}
}


void Topograph::drawBestPath(Bmp& bmp)
{
    int min = drawGreedyPath(bmp,0, POSSIBLE_PATH);
    int best_path;
    for(int i = 0 ; i < height ; i++)
    {
        int path = drawGreedyPath(bmp,i, POSSIBLE_PATH);
        if(path < min)
        {
            min = path;
            best_path = i;
        }
    }
    best = min;
    drawGreedyPath(bmp,best_path, BEST_PATH);
}
