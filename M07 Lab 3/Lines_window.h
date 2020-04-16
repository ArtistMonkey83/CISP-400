#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H

#include "../std_lib_facilities.h"
#include "../GUI/GUI.h"

using namespace  Graph_lib;

struct Lines_window : Graph_lib::Window
{
  Lines_window(Point xy, int w, int h, const string& title);

  private:
    Open_polyline lines;

    Button next_button,
           quit_button,
           style_button,
           menu_button;
    In_box next_x,
           next_y;
    Out_box xy_out;

    Menu color_menu,
         style_menu;

    void change(Color c) {lines.set_color(c);}
    void changeStyle(Line_style c) {lines.set_style(c);} ////////////////style needs changing!!!
    void hide_menu() {color_menu.hide(); menu_button.show();}
    void hide_style() {style_menu.hide(); style_button.show();}

    void red_pressed() {change(Color::red); hide_menu();}
    void blue_pressed() {change(Color::blue); hide_menu();}
    void black_pressed() {change(Color::black); hide_menu();}

    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void style_pressed() {style_button.hide(); style_menu.show();}

    void solid_pressed() {changeStyle(Line_style::solid); hide_style();}
    void dash_pressed() {changeStyle(Line_style::dash);hide_style();}
    void dot_pressed() {changeStyle(Line_style::dot); hide_style();}

    void next();
    void quit();

    static void cb_red(Address, Address pw);
    static void cb_blue(Address, Address pw);
    static void cb_black(Address, Address pw);
    static void cb_menu(Address, Address pw);
    static void cb_style(Address, Address pw);
    static void cb_quit(Address, Address pw);
    static void cb_next(Address, Address pw);
    static void cb_solid(Address, Address pw);
    static void cb_dash(Address, Address pw);
    static void cb_dot(Address, Address pw);
};
#endif
