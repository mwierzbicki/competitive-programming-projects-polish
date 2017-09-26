//
//  main.cpp
//  ptaszek_wzorc
//
//  Created by Marcin Wierzbicki on 03.02.2017.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oi/21/pta
//

#include <cstdio>
#include <algorithm>
#include <deque>
#define LL long long
#define wart first
#define ile second
#define mp make_pair
using namespace std;
const int MAX_N=(1e6);
const int INF=(1e9)+1;
int n,k,q,t[MAX_N],dyn[MAX_N],cnt;
deque<pair<pair<int,int>,int> > kol;

bool mniejszerowne(pair<int,int> a, pair<int,int> b) {
    if (a.first==b.first) {
        if (a.second==b.second) {
            return true;
        }
        else {
            return a.second<=b.second;
        }
    }
    else {
        return a.first<=b.first;
    }
}

void __kol_dodaj(pair<int,int> a) {
    
    int ilee=0;
    while (!kol.empty() && mniejszerowne(a,kol.front().wart)) {
        ilee+=kol.front().ile;
        ilee++;
        kol.pop_front();
    }
    kol.push_front(mp(a,ilee));
}

void __kol_wywal() {
    
    if (kol.back().ile==0) {
        kol.pop_back();
    }
    else {
        kol.back().ile--;
    }
}

pair<int,int> __kol_min() {
    if (kol.empty()) {
        return mp(INF,INF);
    }
    else {
        return kol.back().wart;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&t[i]);
    }
    scanf("%d",&q);
    for (int i=0; i<q; i++) {
        scanf("%d",&k);
        kol.clear();
        cnt=0;
        for (int j=n-2; j>=0; j--) {
            __kol_dodaj(mp(dyn[j+1],t[j+1]));
            cnt++;
            if (cnt>k) {
                __kol_wywal();
                cnt--;
            }
            dyn[j]=__kol_min().first+(t[j]<=__kol_min().second);
            //printf("%d %d %d\n",dyn[j],__kol_min().first,__kol_min().second);
        }
        printf("%d\n",dyn[0]);
    }
    return 0;
}
