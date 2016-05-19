#include <iostream>

using namespace std;

int main(){
  int octal = 077; //this is an octal value, which actually equals 63, never prefix a number with 0 if you want it's literal value.
  string str = "random_string";
  cout << str[2] << endl; // can access INDIVIDUAL index much like in js or python using brackets
  cout << str.length() << endl;  // use the length() method to get the length of a string

  return 0;
}
