//
//  main.cpp
//  temperatura_wzorc
//
//  Created by Marcin Wierzbicki on 29.11.2016.
//  
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oi/18/tem
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#define w first
#define h second
#define mp make_pair
#define PII pair<int,int>
using namespace std;
const int INF=(1e9)+1;
int n,wyn,x,y,poc;

class monoque {
    deque<PII> k;
    public:
    void push(int a) {
        int b=0;
        while (!k.empty() && k.front().w<=a) {
            b+=k.front().h;
            b++;
            k.pop_front();
        }
        k.push_front(mp(a,b));
    }
    void pop() {
        if (!k.empty()) {
            if (k.back().h) {
                k.back().h--;
            }
            else {
                k.pop_back();
            }
        }
    }
    int front() {
        if (k.empty()) {
            return -INF;
        }
        else {
            return k.back().w;
        }
    }
};

monoque m;

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        if (m.front()<=y) {
            m.push(x);
            wyn=max(wyn,i+1-poc);
        }
        else {
            while (m.front()>y) {
                m.pop();
                poc++;
            }
            m.push(x);
        }
    }
    printf("%d",wyn);
    return 0;
}
