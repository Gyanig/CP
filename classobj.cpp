#include <bits/stdc++.h>
using namespace std;

class Zoo{
	private:
		int index;
		string name;
		
	public:
		
		Zoo(int ind,string s){
			this->name=s;
			this->index=ind;
		}
		
		void Display(){
			cout<< index << "\t";
			cout<< name << endl; 
		}
		
		void Input(){
			cin>> index;
			cin>> name;
		}
		
		
};

int main(){
	Zoo* p=new Zoo(10,"Giraffe");
	p->Display();
	
	Zoo tiger(20,"Tiger");
	tiger.Display();
	return 0;
}
