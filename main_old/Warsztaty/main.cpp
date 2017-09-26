//
//  main.cpp
//  warsztaty
//
//  Created by Marcin Wierzbicki on 02.11.2015.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oig/4/war
//

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n,m,k,a,b;
    scanf("%d%d%d",&n,&m,&k);
    int tab[n];
    vector<int> kolorki[k+1];  
    for (int i=0; i<n; i++) {
        scanf("%d",&tab[i]);
        kolorki[tab[i]].push_back(i);
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        while(!kolorki[a].empty()) {
            kolorki[b].push_back(kolorki[a].back());
            kolorki[a].pop_back();
        }
    }
    for (int i=1; i<=k; i++) {
        if (kolorki[i].size()>0) {
            for (int j=0; j<kolorki[i].size(); j++) {
                tab[kolorki[i][j]]=i;
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d ",tab[i]);
    }
    return 0;
}
