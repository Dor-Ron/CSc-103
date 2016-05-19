#include <iostream>
#include <vector>

using namespace std;

int main() {
  int i = 100;
  {
    int i = 20;
    cout << i << endl; // 20, i in local scope
  }
  cout << i << endl; // 100, i in global scope

  return 0;
}


/*
Did theoretical stuff:

Covered heaps, size vs capacity properties of vectors,
capacity doubling w/size, new keyword in heap context,
memory leaks, and variable scopes.

*/
