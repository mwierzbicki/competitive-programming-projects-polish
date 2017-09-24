//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oig/5/tyg
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(0);
    int n, maxx, wynik=1;
    scanf("%d",&n);
    pair<int, int> tab[n];
    for (int i=0; i<n; i++) {
        //cin >> tab[i].first >> tab[i].second;
        scanf("%d %d",&tab[i].first,&tab[i].second);
        tab[i].second = tab[i].first/tab[i].second;
    }
    sort(tab, tab+n);
    maxx = tab[n-1].second;
    for (int i=n-1; i>=0; i--) {
        if (tab[i].second>maxx) {
            maxx = tab[i].second;
        }
        if (tab[i].first<=maxx) {
            wynik++;
            maxx=tab[i].second;
        }
    }
    printf("%d",wynik);
}