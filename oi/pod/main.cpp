//
//  main.cpp
//  pod
//
//  Created by Marcin Wierzbicki on 17.10.2016.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/oi24-1/p/pod/
//
//  Time complexity: O(n + q lg n)
//  Space complexity: O(n)
//

#include <iostream>
#include <algorithm>
#define boost ios_base::sync_with_stdio(0)
using namespace std;
const int MAX_N=(1e6);
int ind,q;
long long n,a,wyn,MOD,dod,l[MAX_N];

int main() {
    boost;
    cin >> n >> q;
    MOD=n-1;
    for (long long i=0; i<n; i++) {
        cin >> l[i];
        dod=(l[i]*i)%MOD;
        wyn=(wyn+dod)%MOD;
    }
    if (wyn!=0) {
        l[wyn]--;
    }
    for (int i=1; i<n; i++) {
        l[i]+=l[i-1];
    }
    for (int i=0; i<q; i++) {
        cin >> a;
        ind=int(upper_bound(l,l+n,a)-l);
        if (ind==n) {
            cout << -1 << endl;
        }
        else {
            cout << ind << endl;
        }
    }
    return 0;
}
