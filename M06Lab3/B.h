/*

Define a class B1 with:
virtual function vf()
non-virtual function f()
pure virtual function pvf()
Define these functions within class B1
Implement each function to output its name (e.g., B1::vf()).
Make the functions public.

*/
#include "std_lib_facilities.h"

using namespace std;

class B1
{
  public:
    virtual void vf(){cout << "B1::vf()"<< endl;}
    void f() {cout << "B1::f()"<< endl;}
    virtual void pvf() const = 0;
};

/*
Derive a class D1 from B1
Define f()
override vf()
override pvf()
*/
class D1: public B1
{
  public:
    void vf() override {cout << "D1::vf()"<< endl;}
    void f() {cout << "D1::f()"<< endl;}
    void pvf() const {cout << "D1::pvf()"<< endl;}

};

/*
Derive a class D2 from D1
override pvf()
*/
class D2: public D1
{
  public:
    void pvf(){cout << "D2::pvf()"<< endl;}
};

/*
Define a class B2 with a pure virtual function pvf()
*/
class B2
{
  public:
    virtual void pvf() const = 0;
};

/*
Derive a class D21 from B2 with a string data member and a member function that overrides pvf()
Initialize the string to "D21::pvf()"
D21::pvf() should output the value of the string and a newline */
class D21 : public B2
{
  public:
    void pvf() const {cout << data << endl;}
  private:
    string data = "D21::pvf()";
};

/*
Define a class D22 that is just like D21 except that its data member is an int
Initialize the int to 22
Your output only needs to output the integer value and a newline */
class D22: public B2
{
  public:
    void pvf() const {cout << data << endl;}
  private:
    int data = 22;
};
/*
Define a global function f() that takes a B2& argument and calls pvf() for its argument.
*/
void f(B2& b) {b.pvf();}
