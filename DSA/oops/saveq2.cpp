#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
using namespace std;

class account{
	protected:
		char cname[20];
		int accno;
		char type;
		int bal;
		int chk_bk;
	public:
		void input(){
		  cout<<"Enter details :name, accno ,type,bal \n";
	        cin>>cname;
	        cin>>accno;
	        cin>>type;
		  cin>>bal;
		  if(type=='C')
		  {
		  	cout<<"Enter check book number for current :"<<endl;
	            cin>>chk_bk;
		  }

		  }
		void display(){
		     cout<<"\n Customer Name :"<<cname;
		     cout<<"\n Account Number :"<<accno;
		     cout<<"\n Type :"<<type;
		     cout<<"\n Balance :"<<bal;
		     cout<<"\n Checkbook number :"<<chk_bk<<endl;;
	     }
		void deposit(){
		     int amt;
		     cout<<"\n Enter the amount to deposit : ";
		     cin>>amt;
		     bal=bal+amt;
	     }
};

class savacct:public account{
      int inter;
      public:
	      int comp_int(){
	         int time1,rate1;
	         cout<<"\n Enter time, rate: ";
		   cin>>time1>>rate1;
	         inter=bal*pow(1+rate1/100.0,time1)-bal;
	         return inter;
	      }

	      void update_bal(){
	         bal=bal+comp_int();
	      }

	      void withdrawal(){
	         int amt;
	         cout<<"\n Enter amount to withdrawn : ";
	         cin>>amt;
	         if(bal>=amt){
	               bal=bal-amt;
	         }
	         else{
	               cout<<"\n The amount cannot be withdrawn ";
	         }
	      }
  };

class curacct:public account{
       int chq_bk;
	 int scharge;
      public:
            int min_bal(){
	          bool flag=true;
	          if(bal<=3000){
	             scharge=0.5*bal;
	             bal=bal-scharge;
	             flag=false;
	          }
	          else{
	             cout<<"\n No penality imposed !";
	          }
	          return flag;
	      }
	      void withdrawal(){
	          int amt;
	          cout<<"\n Enter the amount to withdrawn :";
	          cin>>amt;
		    bool k=min_bal();
	          if(k){
	             if(bal>=amt)
	               bal=bal-amt;
	          }
	          else{
	              cout<<"\n The amount cannot be withdrawn!";
	          }
	      }
   };

int main(){
	
      curacct c1;
      cout<<"Current account creation\n type: C for Current\n Service charge for low balance is 0.5% of balance\n";
      c1.input();
      c1.display();
      c1.deposit();
      c1.display();
      c1.withdrawal();
      c1.display();
      
      savacct s1;
      cout<<"Saving account creation\n type: S for Saving\n";
      s1.input();
      s1.display();
      s1.deposit();
      s1.display();
      s1.update_bal();
      s1.display();
      s1.withdrawal();
      s1.display();
      
      return 0;
}
