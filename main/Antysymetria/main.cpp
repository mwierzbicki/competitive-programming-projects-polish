//
//  main.cpp
//  antysymetria_wzorc
//
//  Created by Marcin Wierzbicki on 27.01.2017.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oi/17/ant
//

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define ll long long
using namespace std;
const int MAX_N=(1e5)*5;
const int MOD=(1e9)+696969;6
int n,pos[MAX_N],wpos,poc,kon,sr;
long long wyn;
int h[MAX_N+2],ah[MAX_N+2],p[MAX_N+1];
long long hel,ahel;
int hh,l,r;
char s[MAX_N+2];

int main() {
    scanf("%d",&n);
    scanf(" %s",s+1);
    p[0]=1;
    for (int i=1; i<=n; i++) {
        p[i]=((ll)p[i-1]*3)%MOD;
        if (s[i]=='0') {
            h[i]=p[i];
        }
        else {
            h[i]=((ll)p[i]*2)%MOD;
        }
        h[i]=(h[i]+h[i-1])%MOD;
        if (s[n-i+1]=='0') {
            ah[i]=((ll)p[i]*2)%MOD;
        }
        else {
            ah[i]=p[i];
        }
        ah[i]=((ll)ah[i-1]+ah[i])%MOD;
    }
    for (int i=1; i<=n-1; i++) {
        if (s[i]!=s[i+1]) {
            poc=0;
            kon=min(i-1,n-i-1);
            while (poc<kon) {
                sr=(poc+kon+1)/2;
                r=i+sr+1;
                l=i-sr-1;
                hel=h[r]-h[l];
                if (hel<0) {
                    hel+=MOD;
                }
                ahel=ah[n-l]-ah[n-r];
                if (ahel<0) {
                    ahel+=MOD;
                }
                hh=abs(l-(n-r));
                if (l<(n-r)) {
                    hel=((ll)p[hh]*hel)%MOD;
                }
                else if (l>(n-r)) {
                    ahel=((ll)p[hh]*ahel)%MOD;
                }
                if (hel==ahel) {
                    poc=sr;
                }
                else {
                    kon=sr-1;
                }
            }
            wyn+=poc;
            wyn++;
        }
    }
    printf("%lld",wyn);
    return 0;
}
