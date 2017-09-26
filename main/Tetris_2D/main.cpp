//
//  main.cpp
//  tetris2d
//
//  Created by Marcin Wierzbicki on 07.02.2017.
//  
//  Original problem statement:
//  http://main.edu.pl/pl/user.phtml?op=showtask&task=tet&con=ALG
//

#include <cstdio>
#include <algorithm>
using namespace std;
//const int MAX_N=(1e6);
const int MAX_NLOG=1048576;
int d[(MAX_NLOG*2)+2],w[(MAX_NLOG*2)+2];
int n,q,l,dl,r=1;

int query(int a, int b) {
    a+=r; b+=r;
    int p=max(d[a],d[b]);
    while (a!=1) {
        if ((a/2)!=(b/2)) {
            if (!(a%2)) {
                p=max(max(d[a+1],w[a+1]),p);
            }
            if (b%2) {
                p=max(max(d[b-1],w[b-1]),p);
            }
        }
        p=max(max(d[a],d[b]),p);
        a/=2; b/=2;
    }
    return p;
}

void insert(int a, int b, int nmax) {
    a+=r; b+=r;
    d[a]=max(d[a],nmax);
    w[a]=d[a];
    d[b]=max(d[b],nmax);
    w[b]=d[b];
    while (a!=1) {
        if ((a/2)!=(b/2)) {
            if (!(a%2)) {
                a++;
                d[a]=max(d[a],nmax);
                w[a]=max(w[a],d[a]);
                a--;
            }
            if (b%2) {
                b--;
                d[b]=max(d[b],nmax);
                w[b]=max(w[b],d[b]);
                b++;
            }
        }
        a/=2; b/=2;
        w[a]=max(w[a*2], w[(a*2)+1]);
        w[b]=max(w[b*2], w[(b*2)+1]);
    }
}

int main() {
    scanf("%d%d",&n,&q);
    while (r<n) {
        r*=2;
    }
    for (int i=0; i<q; i++) {
        scanf("%d%d",&dl,&l);
        insert(l,l+dl-1,query(l,l+dl-1)+1);
    }
    printf("%d",query(0,n-1));
    return 0;
}
