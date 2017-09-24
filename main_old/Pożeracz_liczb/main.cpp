//
// Original problem statement:
// http://main.edu.pl/pl/archive/ontak/2007/poz
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000000000000009

using namespace std;

long long potegi[501];

int main() {
	ios_base::sync_with_stdio();
	//generacja tablicy poteg
	bool bylo[501];
	potegi[1]=2;
	for (int i=2; i<=500; i++) {
		potegi[i]=(potegi[i-1]*2%MOD);
	}
	long long akthasz;
	vector<long long> hasze;
	int n;
	cin >> n;
	int tab[n];
	for (int j=1; j<=500; j++) {
		bylo[j]=1;
	}
	//long long hasze[(n*(n=1+1))/2]
	for (int i=0; i<n; i++) {
		cin >> tab[i];
	}

	//etap 1 - haszowanie
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (hasze.empty()==1) {
				hasze.push_back(potegi[tab[j]]*bylo[tab[j]]%MOD);
				akthasz=potegi[tab[j]]*bylo[tab[j]]%MOD;
				//cout << "zmiana akthasz\n" << akthasz << endl;
			}
			else {
				hasze.push_back(akthasz+(potegi[tab[j]]*bylo[tab[j]]%MOD)%MOD);
				akthasz=akthasz+((potegi[tab[j]]*bylo[tab[j]]%MOD)%MOD);
			}
			bylo[tab[j]]=0;
		}
		for (int j=1; j<=500; j++) {
			bylo[j]=1;
		}
		akthasz=0;
	}
	sort(hasze.begin(), hasze.end());
	cout << unique(hasze.begin(), hasze.end())-hasze.begin();
}