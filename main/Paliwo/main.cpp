//
//  main.cpp
//  paliwo
//
//  Created by Marcin Wierzbicki on 21.09.2015.
//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oi/4/pal
//

#include <cstdio>

using namespace std;

int main() {
    int k, n, check, zmiana, minn=1000001, minnn=0;
    long long wynik=0, wynika=0;
    scanf("%d%d",&k,&n);
    int tab[n][2];
    for (int i=0; i<n; i++) {
        scanf("%d%d",&tab[i][0],&tab[i][1]);
    }
    for (int i=0; i<n-1; i=zmiana) {
        printf("A");
        check=0;
        minn=1000001;
        wynika = 0;
        for (int j=i; j<n; j++) {
            printf("B");
            check = check + tab[j][1];
            if (tab[j][0]<minn) {
                minn=tab[j][0];
                minnn=j;
            }
            if (check>=k) {
                j=n;
            }
        }
        for (int j=i; j<minnn; j++) {
            wynika = wynika + tab[j][1];
        }
        wynik = wynik + (wynika * minn);
        printf("%lld",wynik);
        zmiana = minnn;
    }
    return 0;
}
