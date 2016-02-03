/*
Lecture from February Third, 2016
*/

#include <iostream>

using namespace std;

int main() {
  while (true) {
    double feet, inch, weight, height, BMI;
    cout << "Enter your height in feet:\n";
    cin >> feet;
    if (feet <= 0) break;
    cout << "Enter your height inch\n";
    cin >> inch;
    cout << "Enter your weight in pounds:\n";
    cin >> weight;
    height = 12 * feet + inch;
    BMI =  weight * 1. / (height*height) * 703;
    cout << "Your BMI is: " << BMI << endl;
  }
  cout << "Bye...\n";
  return 0;
}
