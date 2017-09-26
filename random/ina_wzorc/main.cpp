//
//  main.cpp
//  ina_wzorc
//
//  Created by Marcin Wierzbicki on 10.02.2017.
//

//#define DD

#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstdlib>
#define w first
#define h second
#define mp make_pair
#define PII pair<int,int>
using namespace std;
const int INF=(1e9)+1;
const int MAX_N=(1e6);
const int MAX_M=100;
int kl,kr,nl,nr,od,d,n,m,wyn=-INF,dyn[2][MAX_N];
PII mdeque[(MAX_N*2)+1];

struct zapyt {
    int a,b,t;
};

zapyt zap[MAX_N];

deque<PII> k;
void m_push(int a) {
    int b=0;
    while (!k.empty() && k.front().w<=a) {
        b+=k.front().h;
        b++;
        k.pop_front();
    }
    k.push_front(mp(a,b));
}
void m_pop() {
    if (!k.empty()) {
        if (k.back().h) {
            k.back().h--;
        }
        else {
            k.pop_back();
        }
    }
}
int m_front() {
    if (k.empty()) {
        return -INF;
    }
    else {
        return k.back().w;
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&d);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&zap[i].a,&zap[i].b,&zap[i].t); zap[i].a--;
    }
    for (int i=0; i<m-1; i++) {
        for (int j=0; j<n; j++) {
            dyn[0][j]+=zap[i].b-(abs(zap[i].a-j));
        }
        kl=0; kr=0;
        od=d*(zap[i+1].t-zap[i].t);
        m_push(dyn[0][0]);
        for (int j=0; j<n; j++) {
            nl=max(0,j-od);
            nr=min(n-1,j+od);
            while (kl<nl) {
                kl++;
                m_pop();
            }
            while (kr<nr) {
                kr++;
                m_push(dyn[0][kr]);
            }
            dyn[1][j]=m_front();
        }
        while(m_front()!=-INF) {
            m_pop();
        }
        for (int j=0; j<n; j++) {
            dyn[0][j]=dyn[1][j];
        }
    }
    for (int j=0; j<n; j++) {
        wyn=max(wyn,dyn[1][j]+(zap[m-1].b-(abs(zap[m-1].a-j))));
    }
    printf("%d",wyn);
    return 0;
}
