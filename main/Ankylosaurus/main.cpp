//
//  main.cpp
//  ankylosaurus
//
//  Created by Marcin Wierzbicki on 17.04.2016.
//
//  Original problem statement:
//  https://zadania.oig.edu.pl/OIG/stored_files/download/17369575
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=(1e5)*2;
const int MAX_TREE=2*262144+1;

int n,p,r=1,buf,ba,bb,bc;
pair<bool, int> tree[MAX_TREE];

void fmax2pow() {
    while (n>r) {
        r=r<<1;
    }
}

void updateTree(int a, int b, int c, int updatetime) {
    bool statetoupdate=false;
    if (c==1) {
        statetoupdate=true;
    }
    a=r+a-1;
    b=r+b-1;
    tree[a].first=statetoupdate;
    tree[a].second=updatetime;
    if (a==b) {
        return;
    }
    tree[b].first=statetoupdate;
    tree[b].second=updatetime;
    while (a+1!=b) {
        if (a%2==0) {
            tree[a+1].first=statetoupdate;
            tree[a+1].second=updatetime;
        }
        if (b%2==1) {
            tree[b-1].first=statetoupdate;
            tree[b-1].second=updatetime;
        }
        a=a/2;
        b=b/2;
    }
}

bool queryTree(int a) {
    bool currentstate=true;
    int czas=0;
    a=r+a-1;
    while (a>0) {
        if (tree[a].second>czas) {
            currentstate=tree[a].first;
            czas=tree[a].second;
        }
        a=a/2;
    }
    return currentstate;
}

int main() {
    scanf("%d %d",&n,&p);
    fmax2pow();
    for (int i=r; i<n+r; i++) {
        tree[i].first=true;
        tree[i].second=1;
    }
    for (int i=0; i<p; i++) {
        scanf("%d",&buf);
        if (buf==0) {
            scanf("%d %d %d",&ba,&bb,&bc);
            updateTree(ba,bb,bc,i+2);
        }
        else {
            scanf("%d",&ba);
            if(queryTree(ba)) {
                printf("TAK\n");
            }
            else {
                printf("NIE\n");
            }
        }
    }
    return 0;
}
