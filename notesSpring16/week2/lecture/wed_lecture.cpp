#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // output random number between 0 and RAND_MAX
  cout << rand() << endl;

  //use srand() to set a seed for the psuedo-random number generation
  srand(111);

  //use srand() along with time() to get seemingly greater randomness
  srand(time(0));
  
  return 0;
}
