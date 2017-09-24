//
//  main.cpp
//  kapitan
//
//  Created by Marcin Wierzbicki on 06.02.2016.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/amppz/2014/kap
//

#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_N=(1e5)*2;
const int INF=(1e9)+1;

int n,alt;
int odl[MAX_N];
bool bylo[MAX_N];
pair<int, int> v;
pair<pair<int, int>,int> xy[MAX_N];
vector<pair<int, int> > graf[MAX_N];
priority_queue<pair<int,int> > k;

inline void lacz() {
    for (int i=0; i<n; i++) {
        if (i!=0) {
            graf[xy[i].second].push_back(make_pair(min(labs(xy[i].first.first-xy[i-1].first.first),labs(xy[i].first.second-xy[i-1].first.second)),xy[i-1].second));
        }
        if (i!=n-1) {
            graf[xy[i].second].push_back(make_pair(min(labs(xy[i].first.first-xy[i+1].first.first),labs(xy[i].first.second-xy[i+1].first.second)),xy[i+1].second));
        }
    }
}

int main() {
    for (int i=1; i<MAX_N; i++) {
        odl[i]=INF;
    }
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&xy[i].first.first,&xy[i].first.second);
        xy[i].second=i;
    }
    sort(xy,xy+n);
    lacz();
    for (int i=0; i<n; i++) {
        swap(xy[i].first.first,xy[i].first.second);
    }
    sort(xy,xy+n);
    lacz();
    /*for (int i=0; i<n; i++) {
        for (int j=0; j<graf[i].size(); j++) {
            printf("%d %d\n",graf[i][j].first,graf[i][j].second);
        }
        printf("\n");
    }*/
    k.push(make_pair(0,0));
    while (!k.empty()) {
        v=k.top();
        k.pop();
        if (v.second==n-1) {
            printf("%d",odl[n-1]);
            return 0;
        }
        if (!bylo[v.second]) {
            bylo[v.second]=1;
            for (int i=0; i<graf[v.second].size(); i++) {
                alt = odl[v.second]+graf[v.second][i].first;
                if (alt<odl[graf[v.second][i].second]) {
                    odl[graf[v.second][i].second]=alt;
                    k.push(make_pair(-alt,graf[v.second][i].second));
                }
            }
        }
    }
    return 0;
}