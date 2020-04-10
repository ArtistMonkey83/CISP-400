#include"ZoomWindow.h"

using namespace Graph_lib;
{
  ZoomWindow::ZoomWindow(Point xy, int w, int h, const string& title) :Simple_window (xy,w,h,title),
              next_i(Point(x_max()-150,0),70,20,"Center i: "),
              next_r(Point(x_max()-350,0),70,20, "Center r: "),
              next_zoom(Point(x_max()-550,0),70,20 "Zoom Level: ")
{
attach(next_i);
attach(next_r);
attach(next_zoom);

center_i = 0;
center_r = 0;
zoom = 1.0;
}

Bool ZoomWindow::wait_for_button()
{
  Simple_window::wait_for_button();
  string input = next_i.get_string();
  istringstream iss (input);
  iss >> center_i;
  iss.clear();
  iss.str("");
/*
  iss >> center_r;
  iss.clear();
  iss >> zoom;
  iss.clear();
*/
  cout << center_i << endl;
/*
cout << center_r << endl;
cout << zoom << endl;
*/
}

}
