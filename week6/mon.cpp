#include <iostream>
#include <cassert> // in order to use assert()

using namespace std;

int main() {
  string str;
  cout << isalpha('c') << endl; // true because c is a letter
  while (1){
    str = "";  // empty string on each iteration
    cout << "> ";
    getline(cin, str);
    if (str == "") break; // break if getline returns an empty string.
  }
  cout << "Enter width of text: ";
  int width; cin >> width;
  cout << "Width is: " << width << endl;
  return 0;
}

/*

Learnt about why you should use getline() vs cin
Played around some more with vectors
Learnt about isalpha()
Learnt about assert()

*/
