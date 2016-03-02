#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vi(100, 0); //initialize a 100 intiger sequence of 0s

  //see how size and capacity change, when size is exceeded capacity is doubled.
  for (int i = 0; i < 100; ++i) {
    cout << "Size = " << vi.size() << " Capacity = " << vi.capacity() << endl;
    vi.push_back(i); // append i to end of vector vi.
  }


  vi.at(7) // check seventh index
  cout << vi.at(9) == vi[9]; //can use bracket operators as in different languages.

}
