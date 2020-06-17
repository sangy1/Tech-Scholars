#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <map>
using namespace std;
typedef map<string, int> MapType;

int main() {
  char filename[1000], words[1000];
  cout << "Enter a file name and press ENTER: "; // Part to get input for file name
  cin.getline(filename, 1000);

  ifstream myFile;
  myFile.open(filename); // opens file

  if (! myFile) { // case for when file doesn't exist
    cout << filename << " could not be opened.";
    cout << endl;
    return -1;
  }

  string str, fullPhrase;
  int i=1;
  cout << "The text from the " << filename << ": \n";
  while (getline(myFile, str) && i <= 3 ) { // Checks line
    cout << str << "\n";
    strcpy(words, str.c_str());
    fullPhrase += str;
    i++;
  }

  cout << "\n";

  strcpy(words, fullPhrase.c_str());
  MapType m;
  int len = strlen(words);
  char delim[] = " \n";
  char *ptr = strtok(words, delim);

  while (ptr != NULL) {
    ++m[ptr];
    ptr = strtok(NULL, delim);
  }
  for (MapType::iterator iter = m.begin(); iter != m.end(); ++iter) { // Displays number of instances a word has
    cout << iter->first << ": occurred " << iter->second << " times.\n";
  }
return 0;
}
