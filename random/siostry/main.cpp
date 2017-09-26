//
//  main.cpp
//  siostry
//
//  Created by Marcin Wierzbicki on 22.01.2017.
//

#include <cstdio>
using namespace std;
const int MAX_N=(1e6)+1;
const long long MOD=(1e9)+7;
int t;
long long a,b,w[MAX_N];

long long dziel(long long a, long long b) {
    //a * b^(m - 2) === a / b mod m
    long long wyn=1,m=MOD,pot=b;
    m=m-2;
    while (m>0) {
        if (m%2) {
            wyn=(wyn*pot)%MOD;
        }
        m=m/2;
        pot=(pot*pot)%MOD;
    }
    return (a*(wyn%MOD))%MOD;
}

int main() {
    scanf("%d",&t);
    w[0]=1;
    for (long long i=1; i<=MAX_N; i++) {
        w[i]=(w[i-1]*i)%MOD;
    }
    for (int i=0; i<t; i++) {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",dziel(w[b],w[a-1]));
    }
    return 0;
}
