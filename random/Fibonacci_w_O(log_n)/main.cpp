//
//  main.cpp
//  fib w log n
//
//  Created by Marcin Wierzbicki on 05.12.2016.
//

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const long long MOD=(1e9)+7;
const int MAX_LOG=62;
vector<bool> rozklad;

struct macierz {
    long long a,b,c,d;
};

macierz mnoz(macierz a, macierz b) {
    macierz wyn;
    wyn.a=((a.a*b.a%MOD)+(a.b*b.c%MOD))%MOD;
    wyn.b=((a.a*b.b%MOD)+(a.b*b.d%MOD))%MOD;
    wyn.c=((a.c*b.a%MOD)+(a.d*b.c%MOD))%MOD;
    wyn.d=((a.c*b.b%MOD)+(a.d*b.d%MOD))%MOD;
    return wyn;
}

long long poteguj(long long n) {
    macierz fib,szy[MAX_LOG];
    fib.a=0; fib.b=1; fib.c=1; fib.d=1;
    szy[1]=fib;
    for (int i=2; i<MAX_LOG; i++) {
        szy[i]=mnoz(szy[i-1],szy[i-1]);
    }
    while(n>0) {
        rozklad.pb(n%2);
        n/=2;
    }
    for (vector<bool>::iterator it=rozklad.begin(); it!=rozklad.end(); it++) {
        if (*it) {
            fib=mnoz(fib,szy[it-rozklad.begin()+1]);
        }
    }
    return fib.d;
}

int main() {
    long long n;
    ios_base::sync_with_stdio(0);
    cin >> n;
    /*if (n==1) {
        cout << 1;
        return 0;
    }
    n-=2;*/
    n--;
    cout << poteguj(n);
    return 0;
}
