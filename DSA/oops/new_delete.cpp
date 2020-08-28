//new and delete function
// instead of malloc , calloc or realloc or free


#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int *p=new int[10];
	delete[10] p;
	
	return 0;
}
