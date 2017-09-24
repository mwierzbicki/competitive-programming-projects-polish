//
// Original problem statement:
// http://main.edu.pl/pl/archive/oi/18/imp
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
bitset<3001> bylo;
bitset<3001> bylodwa;

int main () {
        ios_base::sync_with_stdio(0);
        int n,m,tempa,tempb;
        int wsk=0;
        cin >> n >> m;
        vector <int> graf[n+1];
        for (int i=0; i<m; i++) {
            cin >> tempa >> tempb;
            graf[tempa].push_back(tempb);
            graf[tempb].push_back(tempa);
        }
        for (int i=1; i<=n; i++) {
            if (!bylodwa[i]) {
                for (int j=0; j<graf[i].size(); j++) {
                    bylo[graf[i][j]]=1;
                }
                for (int j=1; j<=n; j++) {
                    if (bylo[j]==0 && j!=i && bylodwa[j]==0) {
                        graf[i].clear();
                        graf[j].clear();
                        bylodwa[j]=1;
                        bylodwa[i]=1;
                        j=n+1;
                    }
                }
                bylo.reset();
            }
        }
        for (int i=1; i<=n; i++) {
            if (bylodwa[i]!=1) {
                cout << i << " ";
                wsk++;
            }
            if (wsk==n/3) {
                return 0;
            }
        }
}