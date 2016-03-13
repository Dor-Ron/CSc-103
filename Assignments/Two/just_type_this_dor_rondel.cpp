#include <iostream> // cin & cout
#include <cstdlib>  // srand and rand
#include <ctime>    // time
#include <chrono>   // to be able to use namespace std::chrono

using namespace std::chrono;  // #include <chrono> wasn't working...
using namespace std;

string generateRandomString(int length) {
  string returnValue;
  for (int i = 0; i < length; i++) {
      int randomNum = rand() % 123; // z's decimal value is 122, limit is exclusive
      while ((randomNum < 65) || (randomNum >= 91 && randomNum <= 96)) { // exclude decimal 91-96 coding for non-letters
        randomNum = rand() % 123; //keep running rand() until randomNum is an acceptable number
      }
      returnValue += randomNum;
  } return returnValue;
}

int wordDifference(string correctWord, string userWord, bool goodTime) {
  int offset = 0;
  while (correctWord.length() != userWord.length()) {
    if (correctWord.length() > userWord.length()) userWord += " ";  // add space to user input if shorter than generated string
    else correctWord += " "; // else append the generated string with a space
  }
  for (int i = 0; i < correctWord.length(); i++) offset += abs(correctWord[i] - userWord[i]);
  return goodTime ? offset : 2*offset;  // return offset if good time else return double the offset
}

int main() {
  srand(time(0)); // seed randomization
  int letterCount = 5, points = 1000, correct, incorrect, timeAllotted = 5000, time_difference, offset;
  cout << "Welcome to Just Type This, Akira's Version\nType the correct word as fast as you can (case-sensitive)\ntype \"end\" to quit.\n****************\n\n";
  while(1) { //infinite loop
    string luckyWord = generateRandomString(letterCount), userInput;
    cout << "Your current points " << points << " just type [" << letterCount << "] -> " << luckyWord << ": ";
    auto start_time = system_clock::now();
    cin >> userInput;
    auto end_time = system_clock::now();
    time_difference = duration_cast<milliseconds>(end_time-start_time).count();
    bool goodTime = timeAllotted > time_difference; // true means good time
    offset = wordDifference(luckyWord, userInput, goodTime);

    if (offset == 0 && goodTime) {  // words match and good time
      correct += 1;
      incorrect = 0;
      points += 100;
      cout << time_difference << " milliseconds, you made it in time interval " << timeAllotted << "...\n";
      if (correct == 2) cout << "One more for next challenge!!!\n";
    } else if (offset == 0) { // words match and bad time
      correct += 1;
      cout << time_difference << " milliseconds, you **failed** to make it in time interval " << timeAllotted << "...\n";
      if (correct == 2) cout << "One more for next challenge!!!\n";
    } else {  // wrong word
      incorrect += 1;
      correct = 0;
      points -= offset;
      cout << time_difference << " milliseconds, you **failed** to make it in time interval " << timeAllotted << "...\n"
           << "Your penalty is: " << offset << endl;
    }

    if (correct == 3) {  // three consecutive correct
      correct = 0;
      timeAllotted -= 250;
      letterCount += 1;
    } else if (incorrect == 3) { // three consecutive incorrect
      incorrect = 0;
      timeAllotted += 250;
      letterCount -= 1;
    }
    if (userInput == "end" || points < 0 || letterCount == 0) break; // end game
  }
  return 0;
}
