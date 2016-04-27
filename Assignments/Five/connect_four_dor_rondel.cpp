#include <iostream>  // cin & cout
#include <tuple>     // tuple & make_tuple
#include <vector>    // vector
#include <string>    // string
#include <algorithm> // find
#include <map>       // map

using namespace std;

void displayBoard(vector<tuple<int,int>>& board, vector<tuple<int,int>>& p1, vector<tuple<int,int>>& p2){  // prints out board
  cout << "  a   b   c   d   e   f   g\n";  // top row
  for (int i = 1; i < 43; i++){
    auto it1 = find(p1.begin(), p1.end(), board[i-1]);  // see if cell is 'o'
    auto it2 = find(p2.begin(), p2.end(), board[i-1]);  // see if cell is 'x'
    if (i % 7 == 0) { // if last cell in row, add closing pipe
      if (it1 != p1.end()) cout << "| o |\n";
      else if (it2 != p2.end()) cout << "| x |\n";
      else cout << "| . |\n";
    } else {
      if (it1 != p1.end()) cout << "| o ";
      else if (it2 != p2.end()) cout << "| x   ";
      else cout << "| . ";
    }
  }
}

bool isValid(char row, vector<tuple<int,int>>& p1, vector<tuple<int,int>>& p2, map<char, tuple<int,int>>& counter) {
  if (get<0>(counter[tolower(row)]) - 1 < -1)  return false; // row full
  auto it1 = find(p1.begin(), p1.end(), make_tuple(get<0>(counter[tolower(row)]), get<1>(counter[tolower(row)])));
  auto it2 = find(p2.begin(), p2.end(), make_tuple(get<0>(counter[tolower(row)]), get<1>(counter[tolower(row)])));
  if (it1 != p1.end() || it2 != p2.end()) return false; // cell taken
  char r = tolower(row);
  if (r != 'a' && r != 'b' && r != 'c' && r != 'd' && r != 'e' && r != 'f' && r != 'g') return false;  // invalid row
  return true;
}

void drop(char row, vector<tuple<int,int>>& player, map<char, tuple<int,int>>& counter) {
  player.push_back(make_tuple(get<0>(counter[tolower(row)]), get<1>(counter[tolower(row)])));
  counter[tolower(row)] = make_tuple(get<0>(counter[tolower(row)])-1, get<1>(counter[tolower(row)]));
}

char bestMove(vector<tuple<int,int>>& p1, vector<tuple<int,int>>& p2){

}

int main() {
  vector<tuple<int, int>> coordinates, p1, p2;
  for (int i = 0; i <  6; i++){
    for (int j = 0; j < 7; j++) coordinates.push_back(make_tuple(i, j));
  }
  map<char, tuple<int, int>> table;
  table['a'] = make_tuple(5,0); table['b'] = make_tuple(5,1); table['c'] = make_tuple(5,2); // row, (row, bottomPiece)
  table['d'] = make_tuple(5,3); table['e'] = make_tuple(5,4); table['f'] = make_tuple(5,5); table['g'] = make_tuple(5,6);
  while(true) {
    displayBoard(coordinates, p1, p2);
    cout << "Enter your turn: ";
    char turn; cin >> turn;
    if (isValid(turn, p1, p2, table)) drop(turn, p1, table);
    else cout << "invalid move, try again\n";
    if (p1.size() + p2.size() == 42 /*|| connectFour*/) break; //full board (tie) or someone won
  } return 0;
}
