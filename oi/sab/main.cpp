//
//  main.cpp
//  sab
//
//  Created by Marcin Wierzbicki on 30.10.2016.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/oi24-1/p/sab/
//
//  Time complexity: O(n)
//  Space complexity: O(n)
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#define boost ios_base::sync_with_stdio(0)
using namespace std;
const int MAX_N=((1e5)*5)+1;
int n,k,a,pd[MAX_N];
double ulam[MAX_N],wyn,h;
vector<int> g[MAX_N];

void dfs(int v, int o) {
    for (int i=0; i<g[v].size(); i++) {
        dfs(g[v][i],v);
    }
    pd[v]++;
    if (g[v].size()==0) {
        ulam[v]=1.0;
    }
    for (int i=0; i<g[v].size(); i++) {
        h=min((double(pd[g[v][i]])/double(pd[v]-1)),ulam[g[v][i]]);
        ulam[v]=max(ulam[v],h);
    }
    pd[o]+=pd[v];
    return;
}

int main() {
    boost;
    cin >> n >> k;
    for (int i=2; i<=n; i++) {
        cin >> a;
        g[a].pb(i);
    }
    dfs(1,0);
    for (int v=1; v<=n; v++) {
        if (pd[v]>k) {
            wyn=max(wyn,ulam[v]);
        }
    }
    cout.precision(10);
    cout << fixed << wyn;
    return 0;
}
