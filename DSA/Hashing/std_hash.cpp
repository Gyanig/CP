//std::hash STL implementation
#include <bitset>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void stringHash()
{
    string h1 ="Gyanig";
    hash<string> stdhash;
    cout<<"HASH : "<<stdhash(h1)<<endl;
}

void bitsetHash()
{
    bitset<5> h2("10111");
    hash<bitset<5> > stdhash;
    cout<<"HASH : "<<stdhash(h2)<<endl;
}

void vectorHash()
{
    vector<bool> h3{ true, false, true, false };
    hash<vector<bool>> stdhash;
    cout<<"HASH : "<<stdhash(h3)<<endl;
}

void charHash()
{
    char h4='a';
    hash<char> stdhash;
    cout<<"HASH : "<<stdhash(h4)<<endl;
}

int main()
{
    stringHash();
    bitsetHash();
    vectorHash();
    charHash();
    return 0; 
}