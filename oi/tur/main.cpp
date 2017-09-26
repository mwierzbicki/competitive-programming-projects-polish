//
//  main.cpp
//  tur
//
//  Created by Marcin Wierzbicki on 28.10.2016.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/oi24-1/p/tur/
//
//  Time complexity: O(n^2)
//  Space complexity: O(n)
//
//  Work used:
//  A linear-time algorithm for finding Hamiltonian cycles in tournaments
//  Y. Manoussakis
//  Universite Paris-XI, L.R.I., bat. 490, 91405 Orsay cedex, France
//  http://www.sciencedirect.com/science/article/pii/0166218X9290233Z
//

#include <iostream>
#include <vector>
#include <list>
#define boost ios_base::sync_with_stdio(0)
#define pb push_back
#define pf push_front
#define in insert
#define er erase
#define f front()
#define ba back()
#define s size()
#define be begin()
#define e end()
#define c hp
#define x first
#define y second
#define LI_IT list<int>::iterator
const int MAX_N=((1e3)*2);
using namespace std;
bool pyk,g[MAX_N][MAX_N],bylo[MAX_N];
int a,v,n,wsk,twsk,suma,topo[MAX_N],tpos[MAX_N];
list<int> hp,p;
LI_IT jj;
vector<int> spc[MAX_N],ng[MAX_N];
pair<int,int> mie[MAX_N];

inline void wczytaj() {
    boost;
    cin >> n;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            cin >> a;
            if (a==1) {
                g[j][i]=true;
            }
            else {
                g[i][j]=true;
            }
        }
    }
    return;
}

inline void sciezka() {
    hp.pf(0);
    for (int i=1; i<n; i++) {
        if (g[i][hp.f]) {
            hp.pf(i);
        }
        else if (g[hp.ba][i]){
            hp.pb(i);
        }
        else {
            for (LI_IT it=hp.be; it!=prev(hp.e); it++) {
                if (g[*it][i] && g[i][*next(it)]) {
                    hp.in(next(it), i);
                    break;
                }
            }
        }
    }
    return;
}

void cykl() {
    for (LI_IT k=prev(hp.e); k!=next(hp.be); k--) {
        if (g[*k][*hp.be]) {
            if (k==prev(hp.e)) {
                for (LI_IT j=hp.be; j!=hp.e; j++) {
                    spc[wsk].pb(*j);
                }
                wsk++;
                return;
            }
            p.splice(p.be,c,next(k),c.e);
            c.er(next(k),c.e);
            jj=p.be;
            while (jj!=p.e) {
                pyk=0;
                for (LI_IT pp=p.be; pp!=p.e; pp++) {
                    for (LI_IT r=c.be; r!=c.e; r++) {
                        if (g[*pp][*r]) {
                            if (r==c.be) {
                                r=prev(c.e);
                            }
                            else {
                                r--;
                            }
                            c.in(next(r),p.be,next(pp));
                            p.er(p.be,next(pp));
                            jj=p.be;
                            pyk=1;
                            break;
                        }
                    }
                    if (pyk) {
                        break;
                    }
                }
                if (!pyk) {
                    for (LI_IT it=c.be; it!=c.e; it++) {
                        spc[wsk].pb(*it);
                    }
                    wsk++;
                    c=p;
                    p.clear();
                    if (hp.s>0) {
                        cykl();
                    }
                    return;
                }
            }
            for (LI_IT it=c.be; it!=c.e; it++) {
                spc[wsk].pb(*it);
            }
            wsk++;
            return;
        }
    }
    spc[wsk].pb(*hp.be);
    wsk++;
    hp.er(hp.be);
    if (hp.s>0) {
        cykl();
    }
    return;
}

inline void ggen() {
    for (int i=0; i<wsk; i++) {
        for (int j=i+1; j<wsk; j++) {
            if (g[spc[i][0]][spc[j][0]]) {
                ng[spc[i][0]].pb(spc[j][0]);
            }
            else {
                ng[spc[j][0]].pb(spc[i][0]);
            }
        }
    }
    for (int i=0; i<wsk; i++) {
        for (int j=0; j<int(spc[i].s); j++) {
            mie[spc[i][j]].x=i;
            mie[spc[i][j]].y=j;
        }
    }
    return;
}

void dfs(int v) {
    bylo[v]=1;
    for (int i=0; i<ng[v].s; i++) {
        if (!bylo[ng[v][i]]) {
            dfs(ng[v][i]);
        }
    }
    topo[twsk]=v;
    twsk++;
}

inline void toposort() {
    for (int i=0; i<n; i++) {
        if (!bylo[i] && ng[i].s>0) {
            dfs(i);
        }
    }
    return;
}

inline void wypisz() {
    for (int i=0; i<twsk; i++) {
        tpos[topo[i]]=i;
    }
    for (int i=0; i<n; i++) {
        suma=0;
        for (int j=tpos[spc[mie[i].x][0]]; j>=0; j--) {
            suma+=spc[mie[topo[j]].x].s;
        }
        cout << suma << " ";
        for (int j=mie[i].y; j<spc[mie[i].x].s; j++) {
            cout << spc[mie[i].x][j]+1 << " ";
        }
        for (int j=0; j<mie[i].y; j++) {
            cout << spc[mie[i].x][j]+1 << " ";
        }
        for (int j=tpos[spc[mie[i].x][0]]-1; j>=0; j--) {
            for (int k=0; k<spc[mie[topo[j]].x].s; k++) {
                cout << spc[mie[topo[j]].x][k]+1 << " ";
            }
        }
        cout << endl;
    }
    return;
}

inline void wypdwa() {
    if (*hp.be==0) {
        cout << 2 << " " << 1 << " " << 2 << endl << 1 << " " << 2;
    }
    else {
        cout << 1 << " " << 1 << endl << 2 << " " << 2 << " " << 1;
    }
    return;
}

int main() {
    wczytaj();
    sciezka();
    if (n==2) {
        wypdwa();
        return 0;
    }
    cykl();
    ggen();
    toposort();
    wypisz();
    return 0;
}
