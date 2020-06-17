#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
  char filename[301];
  cout << "Enter a file name and press enter: ";
  cin.getline(filename, 301);

  ifstream file_in;
  file_in.open(filename);

  if (! file_in) {
    cout << filename << " could not be opened.";
    cout << endl;
    return -1;
  }

  string str;
  int i=1;
  while (getline(file_in, str) &&i <= 3 ) {
    cout << str << "\n";
    i++;
  }

  return 0;
}
