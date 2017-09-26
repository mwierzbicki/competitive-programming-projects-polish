//
//  main.cpp
//  fla
//
//  Created by Marcin Wierzbicki on 17.10.2016.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/oi24-1/p/fla/
//
//  Time complexity: O(n)
//  Space complexity: O(1)
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#define boost ios_base::sync_with_stdio(0)
using namespace std;
int n,p,b,lx,ld,lg,rx,rd,rg,wyn;
bool fail;

int main() {
    boost;
    cin >> n >> p;
    for (int i=0; i<n; i++) {
        cin >> rx >> rd >> rg;
        if (!fail) {
            b=rx-lx;
            rg--;
            rd++;
            if (abs(rg%2)!=rx%2) {
                rg--;
            }
            if (abs(rd%2)!=rx%2) {
                rd++;
            }
            rd=max(ld-b,rd);
            rg=min(lg+b,rg);
            if (rd>rg || !((max(ld-b,rd) <= min(lg+b,rg)) || (max(rd-b,ld) <= min(rg+b,lg)))) {
                fail=1;
            }
            wyn+=abs(rd-ld+rx-lx)/2;
            lx=rx; ld=rd; lg=rg;
        }
    }
    if (fail) {
        cout << "NIE";
    }
    else {
        cout << wyn;
    }
    return 0;
}
