/*
Author: Dor Rondel
Class: CSc 103
Professor: Akira Kawiguchi
Term: Spring 2016
Section: CC2
Institution: CCNY
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string getWinner(char user, char comp) {
  if (user == comp) {
    return "tied...";
  } else if ((user == 'R' && comp == 'S') || (user == 'S' && comp == 'P') || (user == 'P' && comp == 'R')) {
    return "you won :(";
  } else {
    return "I won :)";
  }
}

string changeCharToString(char character) {
  if (character == 'R') {
    return "Rock";
  } else if (character == 'S') {
    return "Scissors";
  } else {
    return "Paper";
  }
}

int main() {
  cout << "Welcome to the Rock-paper-scissor-simulator.\n"
       << "Please select one of the following options to begin the game:\n"
       << "[R]ock, [P]aper, [S]cissor, or [Q]uit\n"
       << "***************************************************************";

  // Game Setup
  double winCount, lossCount, tieCount;
  char possibleMoves[3] = {'R', 'P', 'S'};

  // Actual Game
  while(true) {
    char playerMove;
    char computerMove = possibleMoves[rand() % 3];
    cout << "\nRock-paper-scissors shoo: ";
    cin >> playerMove;
    string compMove = changeCharToString(computerMove);
    string winner = getWinner(toupper(playerMove), computerMove);
    if (toupper(playerMove) == 'Q') {
      printf("You won %d, lost %d, tied %d. You won %.2f%%\n", (int)winCount, (int)lossCount, (int)tieCount, (double)(winCount / (winCount + lossCount)*100));
      break;
    } else if (toupper(playerMove) == 'R' || toupper(playerMove) == 'S' || toupper(playerMove) == 'P') {
      cout << "I'm " << compMove << ", " << winner;
      if (winner == "tied...") {
        tieCount++;
      } else if (winner == "you won :("){
        winCount++;
      } else {
        lossCount++;
      }
    } else {
      cout << "Oops...";
    }
  }
}
