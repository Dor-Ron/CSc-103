/*
Instructions:

//4.
// Fix this program that computes the area of circle where the Radius is interactively supplied
// It should work for radius values like 1.5
#include <iostream>
using namespace std;

int main( )
{

int radius;

cout << "Enter radius: ";
cin  << radius;

cout << "area = " << 3.4 * Radius * Radius << endl;

}
*/

//Solution

#include <iostream>

using namespace std;

int main() {
  double radius;  // changed primitive data type of variable to allow for non-whole number inputs
  cout << "Enter radius: ";
  cin >> radius; //changed direction of bit shift operator
  cout << "area = " << 3.4 * radius * radius << endl;  //lowercase radius
  return 0; //added return statement
}
