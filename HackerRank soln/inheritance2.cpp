#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle{
	public:
		int a ,b;
		void display()
		{
			cout<<a<<" "<<b<<endl;
		}
		
};
class RectangleArea:public Rectangle{
	public:
		void read_input()
		{
			cin>>a>>b;	
		}	
		
		void display()
		{
			cout<<a*b<<endl;
		}
};

int main()
{
    RectangleArea r_area;

    r_area.read_input();

    r_area.Rectangle::display();
    
    r_area.display();
    
    return 0;
}
