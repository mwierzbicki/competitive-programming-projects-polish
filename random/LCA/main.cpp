//
//  main.cpp
//  LCA
//
//  Created by Marcin Wierzbicki on 12.02.2017.
//

//#define DD

#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
const int MAX_N=(1e3)+2;
const int MAX_LOG=10+2;
int n,t,m,q,a,b,zero,gl[MAX_N],p[MAX_LOG][MAX_N],par[MAX_N];
vector<int> g[MAX_N];
int bylo1[MAX_N],bylo2[MAX_N];

inline void genp() {
    p[0][1]=1;
    for (int i=2; i<=n; i++) {
        p[0][i]=par[i];
    }
    for (int i=1; i<=MAX_LOG; i++) {
        p[i][1]=1;
        for (int j=2; j<=n; j++) {
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}

int findlca(int a, int b) {
    if (gl[a]<gl[b]) {
        swap(a,b);
    }
    if (a==b) {
        return a;
    }
    for (int i=MAX_LOG; i>=0; i--) {
        if (gl[p[i][a]]>=gl[b]) {
            a=p[i][a];
        }
    }
    for (int i=MAX_LOG; i>=0; i--) {
        if (p[i][a]!=p[i][b]) {
            a=p[i][a];
            b=p[i][b];
        }
    }
    return p[0][a];
}

int main() {
    scanf("%d",&t);
    for (int tc=0; tc<t; tc++) {
        scanf("%d",&n);
        gl[1]=0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&m);
            for (int j=0; j<m; j++) {
                scanf("%d",&a);
                par[a]=i;
                g[a].pb(i);
                g[i].pb(a);
            }
        }
        genp();
        printf("Case %d:\n",tc+1);
        scanf("%d",&q);
        for (int i=0; i<q; i++) {
            scanf("%d%d",&a,&b);
            printf("%d\n",findlca(a,b));
        }
    }
    return 0;
}
