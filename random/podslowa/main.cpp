//
//  main.cpp
//  podslowa
//
//  Created by Marcin Wierzbicki on 28.09.2016.
//

#include <iostream>
#include <algorithm>

//#define mD

using namespace std;
const int MAX_N=(2*(1e5))+1;
int n,k,a,lcnt;
long long cnt,wyn;
long long t[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a;
        if (a==0) {
            cnt+=k;
        }
        else {
            cnt--;
        }
        t[i]=cnt;
    }
    if (n==1) {
        cout << 0;
        return 0;
    }
    sort(t, t+n+1);
#ifdef mD
    for (int i=0; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
#endif
    lcnt=1;
    for (int i=1; i<=n; i++) {
        if (t[i]==t[i-1]) {
            lcnt++;
        }
        else {
            wyn+=(lcnt*(lcnt-1))/2;
            lcnt=1;
        }
    }
    wyn+=(lcnt*(lcnt-1))/2;
    cout << wyn;
    return 0;
}
