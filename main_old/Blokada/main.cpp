//
//  main.cpp
//  blokada
//
//  Created by Marcin Wierzbicki on 01.12.2015.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oi/15/blo
//

#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>

const int maxn=1e5;

std::vector<int> graf[maxn];
std::vector<int> mosty[maxn];
int m,t,tt,licz=0,wsk=0;
long long n;
//int mini=maxn+1;
int preo[maxn];
int low[maxn];
int wpd[maxn];
long long wyniki[maxn];
long long sumwpd[maxn];

std::bitset<maxn> bylo;
std::bitset<maxn> part;

void dfs(int w, int ojciec) {
    bylo[w]=true;
    preo[w]=licz;
    low[w]=licz++;
    wyniki[w]=wyniki[w]+((n-1)*2);
    for (int i=0; i<graf[w].size(); i++) {
        if (graf[w][i]!=ojciec) {
            if (bylo[graf[w][i]]==1) {
                low[w]=std::min(low[w],preo[graf[w][i]]);
            }
            else {
                dfs(graf[w][i],w);
                /*if (preo[graf[w][i]]==low[graf[w][i]]) {
                    mosty[graf[w][i]].push_back(w);
                    mosty[w].push_back(graf[w][i]);
                }*/
                if (low[graf[w][i]]>=preo[w]) {
                    part[w]=1;
                    wyniki[w]=wyniki[w]+((n-1-wpd[graf[w][i]])*wpd[graf[w][i]]);
                    sumwpd[w]=sumwpd[w]+wpd[graf[w][i]];
                }
                wpd[w]=wpd[w]+wpd[graf[w][i]];
                low[w]=std::min(low[w],low[graf[w][i]]);
            }
        }
    }
    wyniki[w]=wyniki[w]+((n-1-sumwpd[w])*sumwpd[w]);
    wpd[w]++;
}

int main() {
    scanf("%lld %d",&n,&m);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&t,&tt);
        t--;
        tt--;
        graf[t].push_back(tt);
        graf[tt].push_back(t);
    }
    dfs(0,0);
    //most
    /*
    for (int i=1; i<n; i++) {
        if (low[i]==preo[i]) {
            printf("%d",1);
            return 0;
        }
    }*/
    //p. art
    //A
    if (graf[0].size()>1) {
        part[0]=1;
    }
    /*for (int i=0; i<n; i++) {
        if (low[i]==preo[i]) {
            mosty[i].push_back(preo[i]);
            mosty[preo[i]].push_back(i);
        }
    }*/
    //B
    /*for (int i=0; i<n; i++) {
        printf("wpd[%d]: %d   preo[%d]: %d\n",i+1,wpd[i],i+1,preo[i]);
    }*/
    /*
    for (int i=0; i<n; i++) {
        if (mosty[i].empty()) {
            printf("%lld",(n-1)*2);
        }
    }*/
    for (int i=0; i<n; i++) {
        printf("%lld\n",wyniki[i]);
    }
    return 0;
}