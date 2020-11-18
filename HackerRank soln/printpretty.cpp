#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout<<resetiosflags(ios::uppercase);
        cout<<setw(0);
        cout<<hex<<showbase<<(int)A<<endl;
        cout<<setfill('_')<<right<<setw(15);
        cout<<noshowbase<<setprecision(2)<<fixed<<showpos<<B<<endl;
        cout<<std::noshowpos<<setprecision(9)<<std::scientific<<uppercase<<C<<endl;
	}
	return 0;

}
