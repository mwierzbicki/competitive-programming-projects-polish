//
//  main.cpp
//  rep
//
//  Created by Marcin Wierzbicki on 29.10.2016.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/oi24-1/p/rep/
//
//  Time complexity: O(m + n lg k)
//  Space complexity: O(m + k)
//
//  m and k are mathematical constants tailored for the task.
//

#include <iostream>
#include <algorithm>
#define boost ios_base::sync_with_stdio(0)
#define w first
#define a second.first
#define b second.second
#define mp make_pair
using namespace std;
const int MAX_N=1450;
const int MAX_C=56;
int ciag[MAX_C+1];
int ind,n,x,wsk=1;
long long wzor,xx,iind;
pair<int, pair<int,int> > wart[MAX_N];

int main() {
    boost;
    for (int i=2; i<=MAX_C; i++) {
        for (int j=1; j<i; j++) {
            x=ciag[i]-ciag[j];
            if (x<=int(1e9) && i!=j) {
                wart[wsk]=mp(x,mp(i,j));
                wsk++;
            }
        }
    }
    sort(wart+1,wart+wsk);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        ind=int(lower_bound(wart+1, wart+wsk, mp(x,mp(0,0)))-wart);
        if (wart[ind].w==x) {
            cout << wart[ind].a << " " << wart[ind].b << endl;
        }
        else {
            xx=x;
            iind=ind;
            wzor=58+((xx-54)*2)-((iind-54)*2);
            cout << wzor << " " << wzor-1 << endl;
        }
    }
    return 0;
}
