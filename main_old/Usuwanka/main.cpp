//
// Original problem statement:
// http://main.edu.pl/pl/archive/oi/20/usu
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio();
    int n,k,liczb=0,liczc=0,wsk=0;
    string tekst;
    cin >> n >> k >> tekst;
    vector <int> wyniki;
    int stos[n][2];
    for (int i=0; i<n; i++) {
        if (liczb==k && liczc==1) {
            for (int j=0; j<k+1; j++) {
                wyniki.push_back(stos[wsk-1][1]);
                //cout << "pushujemy: " << stos[wsk-1][1] << endl;
                wsk--;
            }
            liczb=0;
            liczc=0;
            for (int j=1; j<=k+1; j++) {
                if (wsk-j>=0) {
                    if (stos[wsk-j][0]=='b') {
                        liczb++;
                    }
                    else {
                        liczc++;
                    }
                }
                else {
                    j=k+2;
                }
            }
        }
        stos[wsk][0]=tekst[i];
        stos[wsk][1]=i+1;
        wsk++;
        if (tekst[i]=='b') {
            liczb++;
        }
        else {
            liczc++;
        }
        if (wsk>k+1) {
            if (stos[wsk-(k+2)][0]=='b') {
                liczb--;
            }
            else {
                liczc--;
            }
        }
        //cout << "liczb: " << liczb << " liczc: " << liczc << " tekst[i]: " << tekst[i] << endl;
    }
    if (liczb==k && liczc==1) {
        for (int j=0; j<k+1; j++) {
            wyniki.push_back(stos[wsk-1][1]);
            wsk--;
        }
    }
    for (int i=wyniki.size()-1; i>=0; i--) {
        cout << wyniki[i] << " ";
        if (i%(k+1)==0) {
            cout << endl;
        }
    }
}
