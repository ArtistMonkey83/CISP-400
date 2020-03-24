#include "B.h"

int main ()
{
  /*
  Try to create a B1 object. What does the compiler tell you? Why?
  comment out the line of code to remove the error.
  */
  //B1 tryObject;
  //tryobject.vf();
  //tryobject.vf();
  //tryobject.pvf();

  /*
  Declare a D1 object and call f(), vf(), and pvf() for it
  */
  D1 derived1;
  derived1.f();
  derived1.vf();
  derived1.pvf();

  /*
  Declare a reference to B1 (B1&) and initialize that to the D1 object you just defined. Call f(), vf(), and pvf() for that reference.
  */

  B1& baseClass1 = derived1;
  baseClass1.f();
  baseClass1.vf();
  baseClass1.pvf();
  /*
  Declare an object of class D2 and call f(), vf(), and pvf() for it.
  */
  D2 derived2;
  derived2.f();
  derived2.vf();
  derived2.pvf();

  /*
  Declare a D21 and a D22 object
  Call f() with a D21 and a D22
  */
  D21 derived21;
  D22 derived22;

  f(derived21);
  f(derived22);

  return 0;
}














































/*

int main()
{
	// B1 b1;
	D1 d1;
	B1& b1r = d1;
	D2 d2;
	D21 d21("STR");
	D22 d22(666);

	//b1.vf();
	//b1.f();
	//d1.vf();
	//d1.f();
	//b1r.vf();
	//b1r.f();
	//d2.f();
	//d2.vf();
	//d2.pvf();

	d21.pvf();
	d22.pvf();
	printPVF(d21);
	printPVF(d22);

	return 0;
}
 */
