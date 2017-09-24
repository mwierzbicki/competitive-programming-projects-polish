//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/ilocamp/2011/wes
//

#include <cstdio>

using namespace std;

int NWD(int a, int b) {
    int tempp;
    while (b!=0) {
        tempp = b;
        b=a%b;
        a = tempp;
    }
    return a;
}

int main(){
    //ios_base::sync_with_stdio(0);
    int z, n, d;
    scanf("%d",&z);
    int wyniki[z];
    for (int i=0; i<z; i++) {
        scanf("%d%d",&n,&d);
        wyniki[i] = n/(NWD(n,d));
    }
    for (int i=0; i<z; i++) {
        //cout << wyniki[i] << endl;
        printf("%d \n",wyniki[i]);
    }
}