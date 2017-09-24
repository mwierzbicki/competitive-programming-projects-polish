//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oig/6/prz
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int wynik[1000001];
int operacje[1000001];

vector<int> nplusjedynki;

int main () {
    int n,k,kont=1,npjeden=0,wsk=0,maxx=0,maxxx=0,inkr=0,maxn=0;
    scanf("%d%d",&n,&k);
    for (int i=1; i<=k; i++) {
        scanf("%d",&operacje[i]);
        if (operacje[i] == n+1) {
            nplusjedynki.push_back(i);
            operacje[i]=0;
        }
    }
    for (int i=0; i<nplusjedynki.size(); i++) {
        sort(operacje+kont, operacje+nplusjedynki[i]);
        kont=nplusjedynki[i];
    }
    sort(operacje+kont, operacje+k);
    for (int i=1; i<=nplusjedynki[nplusjedynki.size()-1]; i++) {
        if (i!=nplusjedynki[wsk]) {
            if (operacje[i]==operacje[i-1]) {
                maxx++;
                if (maxx>maxxx) {
                    maxxx=maxx;
                }
            }
            else {
                maxx=1;
                if (maxx>maxxx) {
                    maxxx=maxx;
                }
            }
        }
        else {
            wsk++;
            maxn=maxn+maxxx;
            maxx=0;
            maxxx=0;
        }
    }
    if (nplusjedynki.size()==0) {
        inkr=1;
    }
    else {
        inkr=nplusjedynki[nplusjedynki.size()-1];
    }
    for (int i=inkr; i<=k; i++) {
        wynik[operacje[i]]++;
    }
    for (int i=1; i<=n; i++) {
        printf("%d ",maxn+wynik[i]);
    }

    return 0;
}