#include "String.h"

namespace String
{
  //default constructor
  string::string() :sz{0},pChars{nullptr},space{0}{} //could put sz= 0; pChars = nullptr; space = 0; in body if you want
  //constructor what type? null- terminated C-String char* pointer to chars
  string::string(const char* s)
  {
    sz=strlen(s);    //get the length of the string and set it to member variable sz
    pChars = new char[sz];    //allocate new space locally
    space = sz;
    std::copy(s,s+sz,pChars);   //use standard library copy funtion to copy all elements in the range first "s" ,last/second variable "s+sz", to another range beginning at third variable "pChars".
  }
  //constructor what type?  Copy constructor!
  string::string( const string& s)
  {
    pChars = new char[s.sz];
    space = s.space;
    sz = s.sz;
    std::copy(s.pChars,(s.pChars+sz),pChars);
  }

  //copy assignment notice how do you tell the difference?
  string& string::operator=(const string& s)
  {
    delete[] pChars;
    sz = s.sz;
    space = s.space;
    pChars= new char[sz];
    std::copy( s.pChars,(s.pChars+sz),pChars);
    return *this;
  }

//move assignement
  string& string::operator=(const char* s)
  {
    delete [] pChars;
    sz = strlen(s);
    space = sz;
    pChars = new char[sz];
    std::copy(s, s+sz,pChars);
    return *this;
  }

 // move assignement
 string& string::operator=(string&& s)
 {
   cout << "Move" << endl;
   delete [] pChars;
   pChars = s.pChars;
   sz = s.sz;
   space = s.space;
   s.pChars = nullptr;
   s.sz = 0;
   s.space = 0;
   return *this;    //dont forget to return *this!
 }

//destructor
string::~string()
{
  space = 0;
  sz = 0;
  delete[] pChars;
}

// Set operator
char& string::operator[](size_t pos)
{return pChars[pos];}

//Get operator
const char& string::operator[](size_t pos) const
{return pChars[pos];}

//function to reserve space if there is no space left for a char
 void string::reserve(size_t y)
 {
   if(y<= space) return;
   char* omega = new char[y];
   space = y;
   std::copy(pChars,(pChars+sz),omega); //getting ready to go out of scope!
   delete[] pChars;
   pChars = omega;    //point to it so we don't loose it!
 }

//function to push_back a value into the string from a c-string char data type
void string::push_back(const char c)
{
  if(sz==0) {reserve(8);}     //if there is no more space reserve 8
  else if (space ==sz) {reserve (2*space);}
  pChars[sz++]=c; //double the space what does pChars[sz++]=d do? space is updated in reserve!!
}
//return index of first occurrence of s, SIZE_MAX if not found!
size_t string::find(const char* s, size_t pos) const
{
  for(size_t i = pos; pChars[i]!= '\0';i++)
  {
    if(pChars[i]==s[0])
    {
      for(size_t j = i; pChars[j]!= '\0'; j++)
      {
        if(s[j]=='\0')break;
        return i;
      }
    }
  }
  return SIZE_MAX;
}

///check equality ( same size, all charrs the same)
bool operator==(const string& lhs, const string& rhs)
{
  if(lhs.size() != rhs.size()) {return false;}
  for(size_t i = 0; i< lhs.size(); i++)
  {
    if(lhs[i]!=rhs[i]) {return false;}
  }
  return true;        //we only get here if left hand side & right hand side size is equal
                      //and if the value of both at index r are equal as well
}

//check equality with null terminated c-string
bool operator==(const string& lhs, const char* rhs)
{
  if(lhs.size() != strlen(rhs)) {return false;}
  for(size_t i = 0; i<lhs.size();i++)
  {
    if(lhs[i]!= rhs[i]){return false;}
    return true;
  }
}
//greater than operator, true if lhs > rhs
bool operator>(const string& lhs, const string& rhs)
{
  for(size_t i = 0;lhs[i]!= '\0' || rhs[i]!= '\0';i++)
    {if(lhs[i] != rhs[i]) {return lhs[i]> rhs[i];}}
  return lhs.size() > rhs.size();


}
//concatenate two MyStrings, return the result
string operator+(const string& lhs, const string& rhs)
{
  string temp = lhs;
  for(size_t i = 0; i < rhs.size() ; i++) {temp.push_back(rhs[i]);} //concatenation at the end of lhs starting one element at a time till r = rhs.size() "end of the string"
  return temp;
}

//output accessor operation
ostream& operator<<(ostream& os, const string& s)
{
  for(size_t i = 0; i <s.size(); i++) {os << s[i];}
  return os;
}
//input accessor opertaion
istream& operator>> (istream& is, string& s)
{
  //s = " "; now empty s string??

  for(char c; is.get(c) && c != ' ' && c != '\n' && c != '\t';) //for loop that uses y to hold input from istream extraction operation skips over whitespace.
  {s.push_back(c);} //while we have input take that input and push_back into what was empty s string
  //is.clear(); Does this    is.clear(ios::failbit)  clear or set the failbit? Can you explain to someone else?
  return is;  //don't forget to RETURN!
}

} //end of namespace



















/* Try something else?
//greater than operator, true if lhs > rhs
bool operator>(const string& lhs, const string& rhs)
{
  if(lhs.size() != rhs.size()){ return (lhs.size() > rhs.size()) ? true:false;} //if the size of lhs and rhs are not equal return true if lhs.size is > rhs.size otherwise return false
  else if (lhs == rhs) {return false;}
  for(size_t i = 0; i<lhs.size() ; i++)
  {
    if(lhs[i]> rhs[i]) {return true;}
  }
}





//return index of first occurrence of s, SIZE_MAX if not found!
size_t string::find(const char* s, size_t pos) const
{
  size_t i = strstr(pChars,s)-pChars;     ///strstr() returns a pointer to the first occurrence of s in pChars MINUS the value of pChars! use my own loops!
       *****  return(i<0)? SIZE_MAX : i;   **********
  // if r is < 0 return SIZE_MAX else return r
  //return(i<0)? SIZE_MAX : i;

  for(size_t i = pos; pChars[i]!='\0';i++)
  if(pChars[i]== s[0])
  {
    for(size_t j = i; pChars[j]!='\0';j++)  {if(pChars[i+j] != s[j]) break;} //s[j-i]
    return i;
  }
  return SIZE_MAX;
}
*/
