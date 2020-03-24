#include "Simple_window.h"

int main()
{

  using namespace Graph_lib;


  Simple_window win20(Point(100,100), 800, 1000, "8x8 lab 2");

  Vector_ref<Graph_lib::Rectangle> vr;

  for(int i = 0; i < 8; ++i)
  {
    for(int j = 0; j < 8; ++j)
    {
      vr.push_back(new Graph_lib::Rectangle(Point( i*100, j*100), 100,100)); //upper left corner of Rectangle
      //vr[vr.size()-1].set_fill_color(i*8+j);
      if(i==j) //detect if i am on diagonal
      {
        vr[vr.size()-1].set_fill_color(Color::red);
      }
      win20.attach(vr[vr.size()-1]);
    }
  }




Image img1(Point(0,600),"img1.jpg");
Image img2(Point(600,300),"img2.jpg");
Image img3(Point(400,400),"img3.jpg");
Image img4(Point(0,0),"img4.jpg");

win20.attach(img1);
win20.attach(img2);
win20.attach(img3);
win20.attach(img4);

win20.wait_for_button();
//Point p(0,0);

int counter = 0; // i want to jump rows 0-7 is valid when it hits 8(or multiple) go down a row and back to zero
  //i++ and j=0 on mulitple of 8
  //i = 0 when counter is 64

while(true)
{
  counter++;
  if(counter ==64)
  {
    //img4.set_point(0,Point(0,0));
    img4.move(-700,-700);
    counter = 0;
  }
  else if(counter%8 ==0)
  {
    img4.move(-700,100);
  }
  //p.x += 100;
  else img4.move(100,0);

  win20.wait_for_button();
}
}
/*int counter = 1;
    while(true)
    {
        if(counter % 64 == 0 && counter != 0)
        {
            counter = 0;
            img4.move(-700, -700);
        }
        else if(counter % 8 == 0 && counter != 0)
        {
            img4.move(-700, 100);
        }
        else
        {
            img4.move(100, 0);
        }
        counter++;
        win.wait_for_button();
    }

    image.move(-counter*100,100);
*/
