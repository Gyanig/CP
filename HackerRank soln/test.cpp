#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string E;
    getline(cin, E);
    int n1=0,n2=0,n3=0,d=0;
    char a;
    for(int i=0;i<E.length();i++)
    {
        while(isdigit(E[i]))
        {
            d=E[i];    
            n1=d+n1*10;
            i++;
        }
        a=E[i];
        i++;
        while(isdigit(E[i]))
        {
            d=E[i];    
            n2=d+n2*10;
            i++;
        }
        i++;
        while(isdigit(E[i]))
        {
            d=E[i];    
            n3=d+n3*10;
            i++;
        }    
    }
    cout<<n1<<" "<<n2<<" "<<n3<<endl;
    int result=0;
    if(a=='+')
    {
        result=int((n3-n2)/n1);
    }
    else
    {
        result=int((n3+n2)/n1);
    }   

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << result << endl;
}
