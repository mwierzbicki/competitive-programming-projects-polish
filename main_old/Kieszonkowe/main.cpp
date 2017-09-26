//
//  main.cpp
//  kieszonkowe
//
//  Created by Marcin Wierzbicki on 28.09.2015.
//
//  Original problem statement:
//  https://sio2.mimuw.edu.pl/c/pa-2015-1/p/kie/
//

#include <cstdio>

using namespace std;

int main() {
    int n, tempp, minn=1001, suma=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&tempp);
        suma=suma+tempp;
        if (tempp%2==1 && tempp<minn) {
            minn=tempp;
        }
    }
    if (suma%2==1) {
        if (n>1) {
            printf("%d",suma-minn);
            return 0;
        }
        else {
            printf("NIESTETY");
            return 0;
        }
    }
    else {
        printf("%d",suma);
        return 0;
    }
}
