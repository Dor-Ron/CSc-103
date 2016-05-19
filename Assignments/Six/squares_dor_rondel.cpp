#include <cstdlib>  // rand & srand
#include <cctype>   // isdigit
#include <vector>
#include <string>
#include <iostream>  // cin & cout
#include "Simple_window.h"  // next
#include "Graph.h"  // Rectangle
#include <ctime>    // time

using namespace Graph_lib;
using namespace std;

struct Square {
  int side;
  int randX;
  int randY;
};

bool validInput(int side, int w, int h) {
  if (isdigit(side)) return true;
  if (side >= h || side >= w) return false; //greater than window h,w
  return false;
}

int main(){
  srand(time(0));
  Simple_window win(Point(0,0), 500, 500, "Assignment #6");
  while(1) {
    cout << "Enter length of squares";
    int len; cin >> len;
    if (len <= 0) break;
    int rX1 = rand()%(500-len), rX2=rand()%(500-len), rX3=rand()%(500-len),
        rY1=rand()%(500-len), rY2=rand()%(500-len), rY3=rand()%(500-len);
    while(!validInput(len, 500-len, 500-len) {
      cout << "INVALID INPUT! Enter a new length";
      cin.clear(); int len; cin>>len;
      if (len <= 0) break;
    }
    Square sq1;
    Rectangle sq(Point(rX1, rY1), len, len);
    sq.set_fill_color(Color::dark_red);
    win.attach(sq);
    win.wait_for_button();
  } return 0;
}

/*
Ask user for size of 3 squares
run error handling on input
  if good () continue
  else reask
generate 3 squares randomly positioned
get intervals of overlap if exist
  if exist () get w,h of overlap, make a white rectangle show on top using Window::put_on_top()
  else () leave alone
iterate if not 0 or negative input
*/
