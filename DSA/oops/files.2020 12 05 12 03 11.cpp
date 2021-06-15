// C++ implementation to read
// file word by word
#include <bits/stdc++.h>
using namespace std;

// driver code
int main()
{

  char text[10000];

  fstream file;
  file.open ("example.txt", ios::out | ios::in );

  cout << "Write text to be written on file." << endl;
  cin.getline(text, sizeof(text));

  file << text << endl;

  file >> text;
    // extracting words from the file
    while (file >> word)
    {
        if(word[0]=='p')
             cout << word << endl;
    }
file.close();
    return 0;
}
