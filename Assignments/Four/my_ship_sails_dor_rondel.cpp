#include <iostream>   // cin & cout
#include <vector>     // vector
#include <algorithm>  // random_shuffle
#include <cstdlib>    // srand
#include <ctime>      // time
#include <string>     // string

using namespace std;

void suitAmount(vector<string>& player, int& h6, int& s6, int& c6,int& d6) {
  for (int i = 0; i < player.size(); i++) {
    if(player[i][0] == 'H') h6 += 1;
    else if (player[i][0] == 'S') s6 += 1;
    else if (player[i][0] == 'C') c6 += 1;
    else d6 += 1;
  }
}

void showHand(vector<string>& hand, vector<char>& alpha) {
  for (int i = 0; i < hand.size(); i++) {
    cout << " (" << alpha[i] << ")" << " " << hand[i];
  } cout << endl;
}

char smallestSuite(int& h6, int& s6, int& c6, int& d6) {
  if ((h6 != 0 && h6 < s6) && (h6 != 0 && h6 < c6) && (h6 != 0 && h6 < d6)) return 'H';
  else if ((s6 != 0 && s6 < h6) && (s6 != 0 && s6 < c6) && (s6 != 0 && s6 < d6)) return 'S';
  else if ((c6 != 0 && c6 < h6) && (c6 != 0 && c6 < s6) && (c6 != 0 && c6 < d6)) return 'C';
  else if (d6 != 0) return 'D'; else return 'X';
}

string cardToPass(vector<string>& player, char& sm) {
  string pass;
  for (int i =0; i < player.size(); i++) {
    if (sm = 'H') {
      if (player[i][0] == 'H') {
        pass = player[i];
        player.erase(player.begin()+i);
        return pass; break;
      }
    } else if (sm == 'S') {
      if (player[i][0] == 'S') {
        pass = player[i];
        player.erase(player.begin()+i);
        return pass; break;
      }
    } else if (sm == 'C') {
      if (player[i][0] == 'C') {
        pass = player[i];
        player.erase(player.begin()+i);
        return pass; break;
      }
    } else {
      if (player[i][0] == 'D') {
        pass = player[i];
        player.erase(player.begin()+i);
        return pass; break;
      }
    }
  }
}

int main() {
  srand(time(0));
  vector<string> deck = {"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "HA",
                         "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK", "DA",
                         "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK", "SA",
                         "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "CA"
                        };  // vector of all the cards
  random_shuffle(deck.begin(), deck.end());  // shuffle the deck of cards
  vector<string> player0, player1, player2, player3, player4;
  vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  for (int i = 0; i < 7; i++) { //initial filling up the player hands with cards
      player0.push_back(deck[i]);
      player1.push_back(deck[i+7]);
      player2.push_back(deck[i+14]);
      player3.push_back(deck[i+21]);
      player4.push_back(deck[i+28]);
  }
  string pass0, pass1, pass2, pass3, pass4;
  bool shipSails = false; // change to true to end game;

  cout << "Welcome to My Ship Sails: Akira Version. Get all the cards in your hand to be in the same suite.\n";

  while (1) {  //game loop
    int h0=0, s0=0, c0=0, d0=0, h1 =0, d1=0, c1=0, s1=0, h2=0, d2=0, c2=0, s2=0, h3=0, d3=0, c3=0, s3=0, h4=0, d4=0, c4=0, s4=0; // counter for suite
    showHand(player0, letters); cout << "Which one to replace? "; char userInput; cin >> userInput;
    while (!(toupper(userInput) == 'A' || toupper(userInput) == 'B' || toupper(userInput) == 'C' || toupper(userInput) == 'D' || toupper(userInput) == 'E' || toupper(userInput) == 'F' || toupper(userInput) == 'G')) {
      if (userInput == '?') {
        cout << "\nPlayer 1\t"; showHand(player1, letters);
        cout << "\nPlayer 2\t"; showHand(player2, letters);
        cout << "\nPlayer 3\t"; showHand(player3, letters);
        cout << "\nPlayer 4\t"; showHand(player4, letters);
      }
      cout << "Enter Valid Input" << endl << "Which one to replace? "; cin >> userInput;
    }
    char p0choice = toupper(userInput);
    string pass0, pass1, pass2, pass3, pass4;
    if (p0choice == 'A') {
      pass0 = player0[0];
      player0.erase(player0.begin());
    } else if (p0choice == 'B') {
      pass0 = player0[1];
      player0.erase(player0.begin()+1);
    } else if (p0choice == 'C'){
      pass0 = player0[2];
      player0.erase(player0.begin()+2);
    } else if (p0choice == 'D'){
      pass0 = player0[3];
      player0.erase(player0.begin()+3);
    } else if (p0choice == 'E') {
      pass0 = player0[4];
      player0.erase(player0.begin()+4);
    } else if (p0choice == 'F') {
      pass0 = player0[5];
      player0.erase(player0.begin()+5);
    } else {
      pass0 = player0[6];
      player0.erase(player0.begin()+6);
    }

    player1.push_back(pass0);


    char sm1, sm2, sm3, sm4;
    suitAmount(player1, h1, s1, c1, d1);
    sm1 = smallestSuite(h1, s1, c1, d1);
    pass1 = cardToPass(player1, sm1);
    player2.push_back(pass1);
    //p2
    suitAmount(player2, h2, s2, c2, d2);
    sm2 = smallestSuite(h2, s2, c2, d2);
    pass2 = cardToPass(player2, sm2);
    player3.push_back(pass2);
    //p3
    suitAmount(player3, h3, s3, c3, d3);
    sm3 = smallestSuite(h3, s3, c3, d3);
    pass3 = cardToPass(player3, sm3);
    player4.push_back(pass3);
    //p4
    suitAmount(player4, h4, s4, c4, d4);
    sm4 = smallestSuite(h4, s4, c4, d4);
    pass4 = cardToPass(player4, sm4);
    player0.push_back(pass4);

    cout << "Hint: Player 0 passed " << pass0 << " to Player 1.\n"
         << "Hint: Player 1 passed " << pass1 << " to Player 2.\n"
         << "Hint: Player 2 passed " << pass2 << " to Player 3.\n"
         << "Hint: Player 3 passed " << pass3 << " to Player 4.\n"
         << "Hint: Player 4 passed " << pass4 << " to Player 0.\n";

    if (h1 == 7 || s1 == 7 || d1 == 7 || c1 == 7) {
      cout << "My Ship sails! --- Player 1 wins";
      break;
    } else if (h0 == 7 || s0 == 7 || d0 == 7 || c0 == 7) {
      cout << "My Ship sails! --- You win";
      break;
    } else if (h2 == 7 || s2 == 7 || d2 == 7 || c2 == 7) {
      cout << "My Ship sails! --- Player 2 wins";
      break;
    } else if (h3 == 7 || s3 == 7 || d3 == 7 || c3 == 7) {
      cout << "My Ship sails! --- Player 3 wins";
      break;
    } else if (h4 == 7 || s4 == 7 || d4 == 7 || c4 == 7) {
      cout << "My Ship sails! --- Player 4 wins";
      break;
    }
  }

  cout << "[ Final card distributions ]";
  cout << "\nPlayer 0\t"; showHand(player0, letters);
  cout << "\nPlayer 1\t"; showHand(player1, letters);
  cout << "\nPlayer 2\t"; showHand(player2, letters);
  cout << "\nPlayer 3\t"; showHand(player3, letters);
  cout << "\nPlayer 4\t"; showHand(player4, letters);

  return 0;
}
