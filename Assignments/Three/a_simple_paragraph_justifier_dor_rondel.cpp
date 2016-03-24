#include <iostream>
#include <regex>
#include <vector>
#include <string>

using namespace std;

int main(){
  vector<string> words;
  vector<string> sentences;
  regex rgx("([a-zA-Z'-.!?;0-9]+)"); // regular expression for words along with some common punctuation marks
  string paragraph, str;

  while (1){
    str = "";  // empty string on each iteration
    cout << "> ";
    getline(cin, str);
    if (str == "") break; // break if getline returns an empty string.
    paragraph += str + " ";
  }

  regex_iterator<string::iterator> it(paragraph.begin(), paragraph.end(), rgx);
  regex_iterator<string::iterator> end;

  for (; it != end; ++it) words.push_back(it->str()); // add words parsed by regex to vector <words>

  string longestWord = "";
  for (int i = 0; i < words.size(); i++) {
    if (words[i].length() > longestWord.length()) longestWord = words[i];  //find longest word for prompting later
  }

  cout << "> Enter width of text: ";
  int width; cin >> width;

  while (width < longestWord.length()) { //keep prompting user until valid length is entered
    cout << "Length you entered is too small, enter a quantity larger than " << longestWord.length() << ": ";
    cin >> width;
  }

  string textLine, firstLast = "|" + string(width, '-') + "|";
  cout << endl << firstLast << endl;
  for (int i = 0; i < words.size(); i++) {
      if ((textLine.length() + words[i].length()) < width) { //if words do fit on line
          textLine += words[i] + " ";  // make line longer
      } else { //otherwise, if they dont fit on the line
        sentences.push_back(textLine);  // add line to line vector
        textLine = words[i] + " "; // make the new line begin with the current word
      }
  }

  if (!textLine.empty()) sentences.push_back(textLine); // if textLine isn't empty, push_back whats left in it. eg) not enough words for one complete line

  for (int i = 0; i < sentences.size(); i++) {  // print paragraph in correct format
    cout << "|" << sentences[i] << string(width-sentences[i].length(), ' ') << "|\n";
  }

  cout << firstLast << endl;
  return 0;
}
