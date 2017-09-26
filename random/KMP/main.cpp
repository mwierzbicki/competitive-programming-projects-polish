//
//  main.cpp
//  kmp_NAJLEPSZE
//
//  Created by Marcin Wierzbicki on 25.01.2017.
//

#include <iostream>
using namespace std;
string wzorzec,tekst,s;
const int MAX_N=(1e6)+1;
int p[MAX_N],t;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> wzorzec >> tekst;
    s=' '+wzorzec+'#'+tekst;
    p[1]=0;
    for (int i=2; i<=s.size(); i++) {
        while (t>0 && s[t+1]!=s[i]) {
            t=p[t];
        }
        if (s[t+1]==s[i]) {
            t++;
        }
        p[i]=t;
        if (p[i]==wzorzec.size()) {
            cout << i-wzorzec.size()-wzorzec.size()-1 << " ";
        }
    }
    cout << endl;
    for (int i=0; i<=s.size(); i++) {
        cout << p[i] << " ";
    }
    return 0;
}
