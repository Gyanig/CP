#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"Without the seed, produces random same output every excution as srand(1) is set\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<rand()<<" ";
	}
	cout<<endl;
	
	srand(time(0)); //using seed, 0~NULL
	
	cout<<"The seed produces random output every excution as srand() is set seed according to time which changes every excution of program\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<rand()<<" ";
	}
	cout<<endl<<endl;
	
	cout<<"Creating a range of random output\n" <<endl;
	for(int i=0;i<100;i++)
	{
		cout<<rand()%100<<" "; // used to set RAND_MAX also
	}
	cout<<endl;
	
	cout<<"random output ranging between [0,1]"<<endl;
	float N=1;
	cout<<fixed << setprecision(1)<<(float)((double)rand() / ((double)RAND_MAX + 1) * N)<<endl;
	
//	cout<<rand() / (RAND_MAX / N + 1)<<endl;
	
//	if(rand() < (RAND_MAX+1u) / N);
	
	
	return 0;
}
