#include <iostream>
#include <fstream>

using namespace std;

int main(){

  char text[200];

  fstream file;
  file.open ("example.txt", ios::out | ios::in );

  cout << "Write text to be written on file." << endl;
  cin.getline(text, sizeof(text));

  file << text << endl;

  file >> text;
  if(text[0]=='p')
     cout << text << endl;

  file.close();
  return 0;
}
