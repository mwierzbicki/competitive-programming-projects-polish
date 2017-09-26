//
//  main.cpp
//  mistrzostwa
//
//  Created by Marcin Wierzbicki on 29.09.2015.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/pa-2015-1/p/mis/
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
bitset<200000> bylo;
int liczkraw[200000];
vector<int> wierzcholki[200000];
vector<int> obecnaspoj;
vector<int> maxspoj;

void sprawdz(int x) {
    obecnaspoj.push_back(x);
    bylo[x]=1;
    for (int j=0; j<wierzcholki[x].size(); j++) {
        if (bylo[wierzcholki[x][j]]==0) {
            sprawdz(wierzcholki[x][j]);
        }
    }
}

void dfs(int n) {
    for (int k=0; k<n; k++) {
        if (bylo[k]==0) {
            sprawdz(k);
            if (obecnaspoj.size()>maxspoj.size()) {
                swap(obecnaspoj, maxspoj);
            }
            obecnaspoj.clear();
        }
    }
}

void lecimy(int n, int d) {
    if (bylo[n]==0) {
        if (liczkraw[n]<d) {
            bylo[n]=1;
            for (int j=0; j<wierzcholki[n].size(); j++) {
                liczkraw[wierzcholki[n][j]]--;
                if (bylo[wierzcholki[n][j]]==0) {
                    lecimy(wierzcholki[n][j],d);
                }
            }
        }
    }
}

int main() {
    int n,m,d,a,b;
    scanf("%d %d %d",&n,&m,&d);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&a,&b);
        wierzcholki[a-1].push_back(b-1);
        wierzcholki[b-1].push_back(a-1);
    }
    for (int i=0; i<n; i++) {
        liczkraw[i]=wierzcholki[i].size();
    }
    for (int i=0; i<n; i++) {
        if (bylo[i]==0) {
           lecimy(i, d);
        }
    }
    if (bylo.count()==n) {
        printf("NIE");
        return 0;
    }
    dfs(n);
    sort(maxspoj.begin(), maxspoj.end());
    printf("%lu\n",maxspoj.size());
    for (int i=0; i<maxspoj.size(); i++) {
        printf("%d ",maxspoj[i]+1);
    }
    return 0;
}
