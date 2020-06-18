#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
typedef map<string, int> MapCount;
typedef pair<string, int> mypair;



int main() {
  // Step 1
  int maxChar = 301;
  char filename[maxChar], words[1000000];
  cout << "Enter a file name and press ENTER: "; // Part to get input for file name
  cin.getline(filename, maxChar);

  // Step 2
  ifstream myFile;
  myFile.open(filename); // opens file

  // Step 3
  if (! myFile) { // case for when file doesn't exist
    cout << filename << " could not be opened.";
    cout << endl;
    return -1;
  }

  // Step 4
  string str, fullPhrase;
  while (getline(myFile, str)) { // Checks line
    strcpy(words, str.c_str());
    fullPhrase += str;
  }

  cout << "\n";

  strcpy(words, fullPhrase.c_str());
  MapCount m;
  int len = strlen(words);
  char delim[] = " \n";
  char *ptr = strtok(words, delim);

  while (ptr != NULL) {
    ++m[ptr];
    ptr = strtok(NULL, delim);
  }
  for (MapCount::iterator iter = m.begin(); iter != m.end(); ++iter) { // Displays number of instances a word has
    cout << iter->first << ": occurred " << iter->second << " times.\n";
  }


  // Step 5
  myvector<mypair> vec;
  copy(m.begin(), m.end(), back_inserter(vec));

return 0;
}
