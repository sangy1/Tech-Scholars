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

string newFileName = "jobsOrdered.csv";


int main() {
  // Step 1: Read File name
  int maxChar = 301;
  char filename[maxChar], words[1000000];

  cout << "Enter a file name and press ENTER: "; // Part to get input for file name
  cin.getline(filename, maxChar);

  // Step 2: Create ifstream object
  ifstream myFile;
  myFile.open(filename); // opens file

  // Step 3:  Check if file is open
  if (! myFile) { // case for when file doesn't exist
    cout << filename << " could not be opened.";
    cout << endl;
    return -1;
  }

  // Step 4: Count frequencies by using map
  string str, fullPhrase;
  while (getline(myFile, str)) { //adds all the words onto one string
    strcpy(words, str.c_str());
    fullPhrase += str;
  }

  for (int i = 0; i < fullPhrase.length(); i++) {
    if (ispunct(fullPhrase[i])) {
      fullPhrase.erase(i--, 1);
    }
  }

  cout << "\n";

  strcpy(words, fullPhrase.c_str());
  MapCount m;
  int len = strlen(words);
  char delim[] = " •\n1234567890";
  char *ptr = strtok(words, delim);

  while (ptr != NULL) {
    ++m[ptr];
    ptr = strtok(NULL, delim);
  }

  /*for (MapCount::iterator iter = m.begin(); iter != m.end(); ++iter) { // Displays number of instances a word has
    cout << iter->first << ": occurred " << iter->second << " times.\n";
  }*/

  // Step 5a: copy map to vector
  cout << "These are the vectors ordered" << endl;
  vector<mypair> vec;
  copy(m.begin(), m.end(), back_inserter(vec));

  // Step 5b: sort
  sort(vec.begin(), vec.end(),
			[](const mypair& l, const mypair& r) {
				if (l.second != r.second)
					return l.second > r.second;

				return l.first > r.first;
			});

  // Step 5c: Print vector
  for (auto const &mypair: vec) {
		cout << '{' << mypair.first << "," << mypair.second << '}' << '\n';
	}

  // Step 6: save results to csv
  fstream newFile(newFileName, ios::out);
  newFile << "Words" << "," << "Repetitions" << endl;

  for (auto const &mypair: vec) {
    newFile << mypair.first << ", " << mypair.second << "\n";
  }

  vec.clear();

return 0;
}
