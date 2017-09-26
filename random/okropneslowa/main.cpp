//
//  main.cpp
//  okropneslowa
//
//  Created by Marcin Wierzbicki on 08.12.2016.
//

#include <iostream>
#include <cmath>
#include <vector>
#define pb push_back
using namespace std;
const int MAX_N=(1e5)*5;
const int POD=29;
const long long MOD=(1e9+7);
bool np[MAX_N+1];
int n,q,a,b,x,hh;
long long hl,hr,hasze[MAX_N],potegi[MAX_N];
string t;
vector<int> lp;

inline void sito() {
    for (int i=2; i*i<MAX_N; i++) {
        if(!np[i]) {
            for (int j=2; i*j<MAX_N; j++) {
                np[i*j] = 1;
            }
        }
    }
    for (int i=2; i<MAX_N; i++) {
        if ((!np[i])) {
            lp.pb(i);
        }
    }
}

void tnij(int ile) {
    if (a==b || (b-a+1)%ile!=0) {
        return;
    }
    x=(b-a+1)/ile;
    hl=hasze[b-x];
    if (a>0) {
        hl=(hl-hasze[a-1])%MOD;
        if (hl<0) {
            hl=hl+MOD;
        }
    }
    hr=hasze[b];
    hr=hr-hasze[a+x-1];
    hl=hl*potegi[x]%MOD;
    if (hr<0) {
        hr=hr+MOD;
    }
    if (hl==hr) {
        b=a+x-1;
        tnij(ile);
        return;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    sito();
    cin >> n >> t >> q;
    potegi[0]=1;
    hasze[0]=(((long long)(int(t[0])-96))*potegi[0])%MOD;
    for (int i=1; i<n; i++) {
        potegi[i]=(potegi[i-1]*POD)%MOD;
        hasze[i]=(hasze[i-1]+((((long long)(int(t[i])-96))*potegi[i])%MOD))%MOD;
    }
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        a--; b--;
        if (a==b) {
            cout << 1 << endl;
        }
        else {
            hh=b-a+1;
            for (vector<int>::iterator it=lp.begin(); it!=lp.end(); it++) {
                if (*it<=int(sqrt(hh))+1) {
                    tnij(*it);
                }
                else {
                    break;
                }
            }
            tnij(b-a+1);
            cout << b-a+1 << endl;
        }
    }
    return 0;
}
