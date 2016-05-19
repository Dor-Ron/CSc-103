/*
Author: Dor Rondel
Class: CSc 103
Professor: Akira Kawiguchi
Term: Spring 2016
Section: CC2
Institution: CCNY

Notes:
lineCount without Extra Credit work: ~40 (with my spacing I had 38)
lineCount with Extra Credit work: ~50 (with my spacing I had 49 lines)

Extra Credit work done:
  -  Made sure capital C and H are accepted by program as input.
  -  Reprompt user if he enters a letter that isn't C or H
  -  Reprompt user if he enters a number higher than his allowance, 0, or a negative integer
NOTE: if you enter "5 c" instead of "c 5" the program will crash presumingly because you're attempting to store an int in a char and a char in an int..
*/

#include <iostream> //cin & cout
#include <cstdlib>  //srand & rand
#include <ctime>    //time

using namespace std;

int diceRoll() { return rand() % 6 + 1; } // emulates a dice roll, returns psuedo-random number b/w 1 & 6
int opponentBet(int p0Allowance, int p1Allowance) {return p1Allowance >= p0Allowance ? rand() % p1Allowance + 1: (rand() % p1Allowance)/2+1;}  // generate random bet from 1 yen to total yen
char choHanOpponent() { return rand() % 2 == 0 ? 'C' : 'H'; } // if random number is even, opponent bet is even else bet is false
int p0=100, p1=100, p2=100;  // initial user allowances.
string instructions = "\n\n\tEnter \"c\" (even) or \"h\" (odd) and an amount to bet: ";

string getWinner(char bet, int roll) {
  if ((toupper(bet) == 'C' && roll % 2 == 0) || (toupper(bet) == 'H' && roll % 2 != 0)) { //if guesses correctly
      return "won...";
  } return "lost..."; // if didnt win, return lost
}

int adjustAllowance(string result, int pAllowance, int pBet) {
  if (result == "won...") {
    return pAllowance + pBet;
  } return pAllowance - pBet; // if player didn't wint we can assume he lost, no need for else block
}

int main(){
  srand(time(0)); // seed psuedo-randomness, not necessary but increases randomness hence decreasing predictability if played more than once.
  while(1) {      // infinite loop
    char p1ChoHan = choHanOpponent(), p2ChoHan = choHanOpponent();
    int p1Bet = opponentBet(p0, p1), p2Bet = opponentBet(p0, p2);
    int p0Roll = diceRoll() + diceRoll(), p1Roll = diceRoll() + diceRoll(), p2Roll = diceRoll() + diceRoll();
    if (p0 <= 0 || (p1 <= 0 && p2 <= 0)) break; // end game if your balance or opponent balance is less than or equal to 0.

    cout << "\nYou have $" << p0 << "\n\tPlayer1 has $" << p1 << "\n\tPlayer2 has $" << p2 << instructions;
    char p0ChoHan; int p0Bet; cin >> p0ChoHan >> p0Bet;
    while ((toupper(p0ChoHan) != 'C' && toupper(p0ChoHan) != 'H') || (p0Bet > p0 || p0Bet <= 0)) { // check to make  sure user inputted valid input
      cout << "\n\t\t\t**INVALID INPUT**" << instructions;
      cin >> p0ChoHan >> p0Bet;
    }

    string p0win = getWinner(p0ChoHan, p0Roll), p1win = getWinner(p1ChoHan, p1Roll), p2win = getWinner(p2ChoHan, p2Roll);

    p0 = adjustAllowance(p0win, p0, p0Bet); p1 = adjustAllowance(p1win, p1, p1Bet); p2 = adjustAllowance(p2win, p2, p2Bet);

    cout << "\tYou bet $" << p0Bet << " -> " << p0win
         << "\n\tPlayer1 bet $" << p1Bet << " -> " << p1win
         << "\n\tPlayer2 bet $" << p2Bet << " -> " << p2win << endl;
   }
  return 0;
}
