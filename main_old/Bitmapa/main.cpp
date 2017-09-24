//
// Original problem statement:
// http://main.edu.pl/pl/archive/oi/6/bit
//

#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

bitset<183> czyt[183];
bitset<183> bylo[183];
int wyn[183][183];

int main() {
    ios_base::sync_with_stdio(0);
    int n,m,i,j;
    char tempbit;
    cin >> n >> m;
    queue<pair<int,int> > kolejka;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cin >> tempbit;
            czyt[j][i]=tempbit - '0';
            if (czyt[j][i]) {
                kolejka.push(make_pair(j,i));
                bylo[j][i]=czyt[j][i];
                wyn[j][i]=czyt[j][i]-1;
            }
        }
    }
    while (!kolejka.empty()) {
        j=kolejka.front().first;
        i=kolejka.front().second;
        if (j-1>=0) {
            if (bylo[j-1][i]==0) {
                bylo[j-1][i]=1;
                wyn[j-1][i]=wyn[j][i]+1;
                kolejka.push(make_pair(j-1,i));
            }
        }
        if (j+1<m) {
            if (bylo[j+1][i]==0) {
                bylo[j+1][i]=1;
                wyn[j+1][i]=wyn[j][i]+1;
                kolejka.push(make_pair(j+1,i));
            }
        }
        if (i-1>=0) {
            if (bylo[j][i-1]==0) {
                bylo[j][i-1]=1;
                wyn[j][i-1]=wyn[j][i]+1;
                kolejka.push(make_pair(j,i-1));
            }
        }
        if (i+1<n) {
            if (bylo[j][i+1]==0) {
                bylo[j][i+1]=1;
                wyn[j][i+1]=wyn[j][i]+1;
                kolejka.push(make_pair(j,i+1));
            }
        }
        kolejka.pop();
    }
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cout << wyn[j][i] << " ";
        }
        cout << endl;
    }
}