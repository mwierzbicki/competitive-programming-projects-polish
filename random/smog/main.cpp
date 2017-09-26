#include <iostream>
#include <algorithm>
#include <map>
#define z first
#define fi first
#define se second
#define mp make_pair
#define LL long long
#define PLL pair<long long, long long>
using namespace std;
const int MAX_N=(1e5)*5;
const int MAX_D=524288+2;
bool wl[MAX_N];
LL q,gx,gy,a,b,wsk,np=1,d[MAX_D],gdzie[MAX_N],npt[MAX_N];
pair<char, PLL > zap[MAX_N];
PLL tab[MAX_N];
map<PLL, LL> bylo;

bool ccomp(PLL a, PLL b) {
    return a.fi<b.fi;
}

LL pot(LL a) {
    return a*a;
}

void ins(int ind) {
    for (int i=ind; i<MAX_D; i+=(i&(-i))) {
        d[i]++;
    }
    return;
}

void inss(int ind) {
    for (int i=ind; i<MAX_D; i+=(i&(-i))) {
        d[i]--;
    }
    return;
}

int pref(int ind) {
    int wyn=0;
    for (int i=ind; i>0; i-=(i&(-i))) {
        wyn+=d[i];
    }
    return wyn;
}

int query(int a, int b) {
    return pref(b-1) - pref(a-1);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin >> gx >> gy >> q;
    for (int i=0; i<q; i++) {
        cin >> zap[i].fi >> zap[i].se.fi >> zap[i].se.se;
        if (zap[i].fi=='!') {
            zap[i].se.fi-=gx;
            zap[i].se.se-=gy;
        }
        if (zap[i].fi=='!' && bylo[mp(zap[i].se.fi,zap[i].se.se)]==0) {
            bylo[mp(zap[i].se.fi,zap[i].se.se)]=np;
            tab[wsk].fi=(zap[i].se.fi*zap[i].se.fi)+(zap[i].se.se*zap[i].se.se);
            tab[wsk].se=np;
            npt[i]=np;
            np++;
            wsk++;
        }
        if (zap[i].fi=='!') {
            npt[i]=bylo[mp(zap[i].se.fi,zap[i].se.se)];
        }
    }
    sort(tab,tab+wsk);
    for (int i=0; i<wsk; i++) {
        gdzie[tab[i].se]=i;
    }
    for (int i=0; i<q; i++) {
        if (zap[i].z=='!') {
            if (wl[npt[i]]==false) {
                ins(int(gdzie[npt[i]])+1);
                wl[npt[i]]=true;
            }
            else {
                inss(int(gdzie[npt[i]])+1);
                wl[npt[i]]=false;
            }
        }
        else if (zap[i].z=='?') {
            cout << query(int(lower_bound(tab,tab+wsk,mp(pot(zap[i].se.fi),0),ccomp)-tab)+1,
                          int(lower_bound(tab,tab+wsk,mp(pot(zap[i].se.se),0),ccomp)-tab)+1) << endl;
        }
    }
    return 0;
}
