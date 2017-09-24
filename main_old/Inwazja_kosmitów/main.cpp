//
// Original problem statement:
// http://main.edu.pl/pl/archive/pa/2012/inw
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int dl;
	cin >> dl;
	long long rozw[dl+3];
	rozw[0]=0;
	rozw[1]=0;
	rozw[2]=0;
	for (int i=3; i<dl+3; i++) {
		cin >> rozw[i];
	}
	for (int i=3; i<dl+3; i++) {
		rozw[i]=rozw[i]+max(rozw[i-2],rozw[i-3]);
		//cout << rozw[i] << endl;
	}
	cout << max(rozw[dl+1],rozw[dl+2]);
}