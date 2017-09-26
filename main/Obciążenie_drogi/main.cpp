//
//  main.cpp
//  Obciazenie drogi
//
//  Created by Marcin Wierzbicki on 27.01.2016.
//
//  Original problem statement:
//  http://smurf.mimuw.edu.pl/node/609
//

#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N=((1e5)*5)+1;
const int MAX_LOG=21;

vector<int> graf[MAX_N];
int n,m,a,b,c;
int gl[MAX_N], par[MAX_N], p[MAX_N][MAX_LOG];
long long maxx;
long long pim[MAX_N];
bitset<MAX_N> bylo;

//1. liczymy glebokosci dfsem
//2. generujemy tablice p[n][n log n]
//3. sprawdzamy lca kazdej pary na wejsciu i do tablicy
//   wprowadzamy co gdzie sie zaczyna i konczy
//4. dfsem uzywajac zmian w poszczegolnych wierzcholkach
//   robimy symulacje od lisci
//5. wynik

long long dfs(int v) {
    long long val=0;
    bylo[v]=1;
    for (int i=0; i<graf[v].size(); i++) {
        if (!bylo[graf[v][i]]) {
            gl[graf[v][i]]=gl[v]+1;
            par[graf[v][i]]=v;
            val=val+dfs(graf[v][i]);
        }
    }
    val+=pim[v];
    maxx=max(val,maxx);
    return val;
}

inline void genp() {
    p[0][0]=0;
    for (int i=1; i<=n; i++) {
        p[i][0]=par[i];
    }
    for (int i=1; i<=MAX_LOG; i++) {
        for (int j=0; j<n; j++) {
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}

int findlca(int f, int s) {
    if (gl[f]<gl[s]) {
        swap(f,s);
    }
    for (int i=MAX_LOG; i>=0; i--) {
        if (gl[p[f][i]]>=gl[s]) {
            f=p[f][i];
        }
    }
    for (int i=MAX_LOG; i>=0; i--) {
        if (p[f][i]!=p[s][i]) {
            f=p[f][i];
            s=p[s][i];
        }
    }
    return p[f][0];
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n-1; i++) {
        scanf("%d %d",&a,&b);
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(0);
    genp();
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a,&b,&c);
        //printf("%d\n",findlca(a,b));
        pim[findlca(a,b)]=pim[findlca(a,b)]-(2*c);
        pim[a]+=c;
        pim[b]+=c;
    }
    for (int i=0; i<n; i++) {
        bylo[i]=0;
    }
    dfs(0);
    printf("%lld",maxx);
}
