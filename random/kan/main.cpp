//
//  main.cpp
//  kan
//
//  Created by Marcin Wierzbicki on 29.09.2016.
//

#include <iostream>
#include <algorithm>

#define mD

using namespace std;
const int MAX_N=(1e5)+1;
const int INF=(1e9)+2;
int n,p,pol,wsk,wyn,t[MAX_N],poprawa=1;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t, t+n+1);
    //while (poprawa!=0) {
        for (int i=n; i>n/2; i--) {
            pol=i/2;
            wsk=upper_bound(t,t+pol+1,t[i]/2)-t-1;
            //cout << wsk << " " << t[wsk] << endl;
            if (wsk!=0) {
                t[wsk]=INF;
                t[i]=INF;
                wyn++;
            }
            else {
                cout << wyn;
                return 0;
            }
        }
    //}
    cout << wyn;
    return 0;
}
