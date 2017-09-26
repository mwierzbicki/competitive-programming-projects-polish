//
//  main.cpp
//  siano
//
//  Created by Marcin Wierzbicki on 29.09.2015.
//
//  Original problem statement:
//  https://main2.edu.pl/c/potyczki-algorytmiczne-2015/p/sia/
//

#include <cstdio>

int doodjecia[500000];

int main() {
    int n,m,poc,kon,sr;
    scanf("%d %d",&n,&m);
    int tab[n];
    int zapyt[m][2];
    long long prefsum[n+1];
    prefsum[0]=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&tab[i]);
        prefsum[i+1]=tab[i]+prefsum[i];
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d",&zapyt[i][0],&zapyt[i][1]);
    }
    for (int i=0; i<m; i++) {
        poc = 0;
        kon = n-1;
        while (poc<kon) {
            sr = (poc+kon)/2;
            if ((tab[sr]<<(zapyt[i][0]-1))-doodjecia[sr] >= zapyt[i][1]) {
                kon = sr;
            }
            else {
                poc = sr + 1;
            }
        }
        printf("%lld\n",(prefsum[n]-prefsum[poc])<<(zapyt[i][0]-1));
        for (int j=poc; j<n; j++) {
            doodjecia[j]=doodjecia[j]+zapyt[i][1];
        }
    }
    return 0;
}
