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
  // Step 1: Read File name
  int maxChar = 301;
  char filename[maxChar], words[1000000];
  //cout << "Enter a file name and press ENTER: "; // Part to get input for file name
  filename[maxChar] = "/Users/egekacmaz/Downloads/jobs.csv";

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
  myFile.close();

  for (int i = 0; i < fullPhrase.length(); i++) {
    if(ispunct(fullPhrase[i])) {
      fullPhrase.erase(i--, 1);
    }
  }

  cout << "\n";

  strcpy(words, fullPhrase.c_str());
  cout << fullPhrase;
  MapCount m;
  int len = strlen(words);
  char delim[] = " \n•";
  char *ptr = strtok(words, delim);

  while (ptr != NULL) {
    ++m[ptr];
    ptr = strtok(NULL, delim);
  }


  // Step 5a: copy map to vector
  cout << "These are the vectors ordered" << endl;
  vector<mypair> vec;
  copy(m.begin(), m.end(), back_inserter(vec));

  // Step 5b: sort
  sort(vec.begin(), vec.end(),
			[](const mypair& l, const mypair& r) {
				if (l.second != r.second)
					return l.second < r.second;

				return l.first < r.first;
			});


  char outFilename[301];
  //cout << "Enter a output file name and press ENTER: "; // Part to get input for file name
  outFilename[301] = "output1.csv";
  ofstream outFile;
  outFile.open(outFilename);

if(!outFile){
cout  << endl << "File could not be opened.";
cout << endl;
return -1;
  }


  // Step 5c:Load vector to a csv
  outFile << "Most frequented keywords (ascending): , Repetition"<<endl;
  for (auto const &mypair: vec) {
      int i=0;
      bool cx= true;
      string str = mypair.first;
      while (i < str.length())
      {
        if (ispunct(str.at(i))) cx = false;
        i++;
      }
        if(cx)
            outFile << mypair.first << "," << mypair.second << '\n';
	}
cout << endl<<"Filesize: " << vec.size() <<endl;
outFile.close();

//5115
return 0;
}
