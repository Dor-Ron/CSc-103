/*
Instructions:

//3
//Fix the program
#include <iostream>
using namespace std;


int Main(  )
{

	cout << "Enter first number:  << endl;
	cin >> num1;
	cout << "Enter second number: " << endl;
	cin >> num1;

	//You do not need another variable to hold the sum
	//You can output(print) the value of an expression
	cout << "The sum of << num1 << " and "
	    << num2 << " is "  << num1 + num2;

	return 0;

}
*/

//Solution
#include <iostream>

using namespace std;

int main() {  // lowercase the M
  int num1, num2; // declare 2 variables
	cout << "Enter first number: "  << endl; //close quotations
	cin >> num1;
	cout << "Enter second number: " << endl;
	cin >> num2; //change name to num2
	cout << "The sum of " << num1 << " and " //close quotations
	    << num2 << " is "  << num1 + num2 << endl; //added endl for personal preference
	return 0;
}
