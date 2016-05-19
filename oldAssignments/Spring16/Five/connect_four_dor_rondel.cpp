#include <iostream>   // cin & cout
#include <tuple>      // tuple & make_tuple
#include <vector>     // vector
#include <string>     // string
#include <algorithm>  // find
#include <map>        // map
#include <cmath>      // rand

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
      else if (it2 != p2.end()) cout << "| x ";
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

#if 0
int getScore(char per, char col, vector<tuple<int,int>>& p1, vector<tuple<int,int>>& p2, map<char, tuple<int,int>>& pos){
  vector<tuple<int,int>> dx = (per='p') ? p1 : p2, dy = (dx==p1) ? p2 : p1;
  int surrounding = 1, open = 0, winningPos = 0, connectFour = 0;
  bool hl=1, hr=1, vu=1, vd=1, lu=1, ld=1, ru=1, rd=1;
  top = pos[col]; // board position if piece placed
  for (int i = 1; i <= 4; i++){
    if (hl && get<0>(top) >= 0 && get<1>(top)-i >= 0) {
      auto dx = find(p1.begin(), p1.end(), make_tuple(get<0>(top), get<1>(top)-i));
      auto dy = find(p2.begin(), p2.end(), make_tuple(get<0>(top), get<1>(top)-i));
      if ()
    }
  } return surrounding * 2 + open + winningPos + connectFour;
}
#endif

#if 0 //segmentation fault: 11
char connectFour(vector<tuple<int,int>>& p1, vector<tuple<int,int>>& p2){
  int h1=0, v1=0, l1=0, r1=0, h2=0, v2=0, l2=0, r2=0;
  tuple<int,int> tail1 = p1[p1.size()-1], tail2 = p2[p2.size()-1];
  for (int i = 1; i <= 3; i++){
    auto horizLeft1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1),  get<1>(tail1) - i));
    auto horizLeft2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2),  get<1>(tail2) - i));
    auto horizRight1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1), get<1>(tail1) + i));
    auto horizRight2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2), get<1>(tail2) + i));
    auto vertUp1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)+i, get<1>(tail1)));
    auto vertUp2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)+i, get<1>(tail2)));
    auto vertDown1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)-i, get<1>(tail1)));
    auto vertDown2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)-i, get<1>(tail2)));
    auto leftUp1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)-i, get<1>(tail1)-i));
    auto leftUp2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)-i, get<1>(tail2)-i));
    auto leftDown1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)-i, get<1>(tail1)-i));
    auto leftDown2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)-i, get<1>(tail2)-i));
    auto rightUp1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)+i, get<1>(tail1)+i));
    auto rightUp2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)+i, get<1>(tail2)+i));
    auto rightDown1 = find(p1.begin(), p1.end(), make_tuple(get<0>(tail1)+1, get<1>(tail1)-i));
    auto rightDown2 = find(p2.begin(), p2.end(), make_tuple(get<0>(tail2)+1, get<1>(tail2)-i));
    if (horizLeft1 != p1.end()) h1++; if (horizRight1 != p1.end()) h1++;
    if (horizLeft2 != p2.end()) h2++; if (horizRight2 != p2.end()) h2++;
    if (vertUp1 != p1.end()) v1++; if (vertDown1 != p1.end()) v1++;
    if (vertUp2 != p2.end()) v2++; if (vertDown2 != p2.end()) v2++;
    if (leftUp1 != p1.end()) l1++; if (leftDown1 != p1.end()) l1++;
    if (leftUp2 != p2.end()) l2++; if (leftDown2 != p2.end()) l2++;
    if (rightUp1 != p1.end()) r1++; if (rightDown1 != p1.end()) r1++;
    if (rightUp2 != p2.end()) r2++; if (rightDown2 != p2.end()) r2++;
    if (h1 >= 4 || v1 >= 4 || l1 >= 4 || r1 >= 4) return 'p'; // player won
    else if (h2 >= 4 || v2 >= 4 || l2 >= 4 || r2 >= 4) return 'c'; // computer won
    else return 'x'; // neither won
  }
}
#endif

int main() {
  bool fourConsecutive = false;
  vector<tuple<int, int>> coordinates, p1, p2;
  for (int i = 0; i <  6; i++){
    for (int j = 0; j < 7; j++) coordinates.push_back(make_tuple(i, j));
  }
  vector<char> columns = {'a','b','c','d','e','f','g'};
  map<char, tuple<int, int>> table;
  table['a'] = make_tuple(5,0); table['b'] = make_tuple(5,1); table['c'] = make_tuple(5,2); // row, (row, bottomPiece)
  table['d'] = make_tuple(5,3); table['e'] = make_tuple(5,4); table['f'] = make_tuple(5,5); table['g'] = make_tuple(5,6);
  while(1) {
    bool t = false;  
    displayBoard(coordinates, p1, p2);
    cout << "Enter your turn: ";
    char turn; cin >> turn;
    if (turn == '?') cout << "Best move function not yet implemented.\n";
    if (isValid(turn, p1, p2, table)) { drop(turn, p1, table); t = true; }
    else cout << "invalid move, try again\n";
    if (t) {
      if (isValid(columns[rand()%7], p1, p2, table)) drop(columns[rand()%7], p2, table); // used to simulate comp move NOTE: uses rand, minimax not successfully implemented
    }
    /* char gameState = connectFour(p1,p2);
    if (gameState == 'p') {
      cout << "You win! Congratulations\n";
      fourConsecutive = true;
    } else if (gameState == 'c') {
      cout << "The computer wins.... You lost :(\n";
      fourConsecutive = true;
    } */ //would've used if connectFour didnt yield segmentation fault
    if (p1.size() + p2.size() == 42 || fourConsecutive) break; //full board (tie) or someone won
  } return 0;
}
