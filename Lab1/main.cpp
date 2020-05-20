#include<list>
#include<ostream>
#include<iostream>
#include<vector>

using namespace std;

template<typename Iter1>
ostream& print_container(Iter1 fl, Iter1 el, ostream& os)
{
  for(Iter1 p = fl;p!= el;p++)
  {
    os << *p << " ";
  }
  os << endl;
  return os;
}

template<typename Iter1, typename T>
void addX(Iter1 fl, Iter1 el, const T& x)
{
for(Iter1 p = fl; p != el;p++) {*p +=x;}
}

template<typename Iter1, typename T>
Iter1 my_find(Iter1 fl, Iter1 el, const T& x)
{
while(fl!=el && *fl!=x)
++fl;
return fl;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 fl, Iter1 el, Iter2 f2)
{
  for(Iter1 p = fl; p != el; p++)
  {
    *f2 = *p;
    f2++;
  }
  return f2;
}


int main()
{
  int arr[] = { 0,1,2,3,4,5,6,7,8,9}; //array<int,10> a = { 0,1,2,3,4,5,6,7,8,9};
  vector<int> v(arr, arr+10); //vector<int> v1(a[0],a[9]);
  list<int> ls(arr,arr+10);   //list<int> v2(a[0],a[9]);
  auto iter1 = arr;
  auto iter2 = arr+10;

//is it easier to read?
  vector<int>::iterator iter3 = v.begin();
  vector<int>::iterator iter4 = v.end();
  list<int>::iterator iter5 = ls.begin();
  list<int>::iterator iter6 = ls.end();

  addX(iter1,iter2,2);
  addX(iter3,iter4, 3);
  addX(iter5, iter6,5);

  my_copy(iter1,iter2,iter3);
  my_copy(iter5,iter6,iter1);

  for(int i =0;i< 10;i++) { cout << arr[i]<< " ";}
  cout<< endl;

  my_find(iter3, iter4, 3);
  print_container(iter3,iter4,cout);
  my_find(iter5,iter6,27);
  print_container(iter5, iter6,cout);

  cout << "3 found in the vector at index 1\n";
  cout << "27 not found in the list.\n";
  return 0;
}


























/* First Try

template<typename Iter1, typename T>
Iter1 my_find(Iter1 fl, Iter1 el, const T& x)
{
  for (Iter1 p = fl;p!= el; p++)
  {
    if(*p == x)
    {cout <<"Found\n "; return p;}
    p++;
  }
  cout << "Not found "<< endl;
  return el;
}




cout << "Test 1" << endl;
my_copy(a.begin(),a.ed(),v1,begin());
cout << "Test 2" << endl;
my_copy(v2.begin(),v2.end(),a.begin());
vector<int>::iterator Iter1 = my_find(v1.begin(),v1.end(),3);
if(Iter1 != v1.end()) print_container(v1.begin(),v1end(),cout);
list<int>::iterator Iter2= my_find(v2.begin(),v2.end(),27);
if*Iter2 != v2.end()) print_container(v2.begin(),v2.end(),cout);

*/
