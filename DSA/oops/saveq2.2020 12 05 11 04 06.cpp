#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

class account{
	protected:
	      char cname[20];
	      int accno;
	      char type;
	      int bal;
	public:
	      void input(){
	        cout<<"Enter details";
		  cin>>cname;
		  cin>>accno;
		  cin>>type;
		  cin>>bal;
	      }
	      void display(){
	            cout<<"\n Customer Name "<<cname;
	            cout<<"\n Account Number "<<accno;
	            cout<<"\n Type "<<type;
	            cout<<"\n Balance "<<bal;
	      }
	      void deposit(){
	            int amt;
	            cout<<"\n Enter the amount to deposit";
	            cin>>amt;
	            bal=bal+amt;
	      }
};
class savacct:public account{
      int inter;
      public:

      int comp_int(){
         int time1,rate1;
         rate1=10;
         cout<<"\n Enter time";cin>>time1;
         inter=bal*pow(1+rate1/100.0,time1)-bal;
         return inter;
      }

      void update_bal(){
         bal=bal+comp_int();
      }

      void withdrawal(){
         int amt;
         cout<<"\n Enter amount to withdrawn";
         cin>>amt;
         if(bal>=amt){
               bal=bal-amt;
         }
         else{
               cout<<"\n The amount cannot be withdrawn";
         }
      }
};

class curacct:public account{
	int chq_bk;
  

      void withdrawal(){
          int amt;
          cout<<"\n Enter the amount to withdrawn";
          cin>>amt;
          if(bal>=amt)
          {
             bal=bal-amt;
          }
          else{
              cout<<"\n The amount cannot be withdrawn";
          }
      }
};

void main(){
      curacct c1;
      savacct s1;
      c1.input();
      c1.display();
      c1.deposit();
      c1.display();
      c1.withdrawal();
      c1.display();
      s1.input();
      s1.display();
      s1.deposit();
      s1.display();
      s1.withdrawal();
      s1.display();
}