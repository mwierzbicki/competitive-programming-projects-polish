//
//  main.cpp
//  drzewo potegowe obciazenie
//
//  Created by Marcin Wierzbicki on 09.02.2016.
//  Copyright © 2016 Marcin Wierzbicki. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX_N=10;
int tree[16+1];
int n,m,bufor,bufor2;

void insert(int x, int v)
{
    while(x < 17) {
        cout << x << endl;
        tree[x] += v;
        x += (x&(-x));
    }
}

int sum(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += tree[x];
        x -= (x&(-x));
    }
    return res;
}

int query(int a, int b)
{
    return sum(b) - sum(a-1);
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> bufor;
        insert(i,bufor);
    }
    for (int i=1; i<=16; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> bufor >> bufor2;
        cout << query(bufor, bufor2) << endl;
    }
    return 0;
}
