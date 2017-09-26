//
//  main.cpp
//  Leśne Okręgi
//
//  Created by Marcin Wierzbicki on 02.02.2016.
//  Copyright © 2016 Marcin Wierzbicki. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

const int MAX_N=(1e3)*2;
const double EPS=(1e-9);

using namespace std;

int n,a,b;
int xy[4][MAX_N+1];
double cxy[4][MAX_N+1];
double odl1,odl2,odl3;
int wsk[4],wskt1,wskt2;
long long wyn;
long long licz;
int p,s,k;
int rabota;
bool y;
long wynik;

double fodl (int x1, int x2, int y1, int y2) {
    wynik=((labs(x1-x2)*labs(x1-x2))+(labs(y1-y2)*labs(y1-y2)));
    return sqrt(double(wynik));
}

void bs(int t) {
    if (t==0 || t==1) {
        y=true;
    }
    else {
        y=false;
    }
    s=wsk[t]/2;
    p=0;
    k=wsk[t];
    //printf("%d %d %d\n",p,s,k);
    while(p<k) {
        if (y) {
            odl2=fodl(xy[t][s],0,0,odl1);
        }
        else {
            odl2=fodl(0,odl1,xy[t][s],0);
        }
        
        if (abs(odl2-odl3)<EPS) {
            rabota++;
            p=k;
        }
        else if (odl2>odl3) {
            k=s;
        }
        else if (odl2<odl3){
            p=s+1;
        }
        s=(p+k)/2;
    }
}

void scheck() {
    //uzywaj tablicy !!! cpy !!! do porownywania double'i
    //2 razy n^2 log n
    for (int i=0; i<wsk[0]; i++) {
        for (int j=0; j<wsk[1]; j++) {
            j=8;
            
            odl1=(cxy[0][i]-cxy[1][j])/2;
            odl3=(cxy[0][i]+cxy[1][j])/2;
            //binsearch sprawdzajacy czy jest taki wierzcholek na gorze czy na dole ktory sie z nami laczy
            //najpierw gora potem dol
            rabota=0;
            bs(2);
            bs(3);
            //printf("r: %d\n",rabota);
            if (rabota==2 && xy[0][i]!=xy[1][j]) {
                printf("WUT: %f %f\n",cxy[0][i],cxy[1][j]);
                wyn++;
            }
            rabota=0;
        }
    }
    for (int i=0; i<wsk[2]; i++) {
        for (int j=0; j<wsk[3]; j++) {
            odl1=(cxy[2][i]-cxy[3][j])/2;
            odl3=(cxy[2][i]+cxy[3][j])/2;
            //binsearch sprawdzajacy czy jest taki wierzcholek na gorze czy na dole ktory sie z nami laczy
            //najpierw gora potem dol
            rabota=0;
            bs(0);
            bs(1);
            //printf("R: %d\n",rabota);
            if (rabota==2) {
                printf("wut: %f %f\n",cxy[0][i],cxy[1][j]);
                wyn++;
            }
            rabota=0;
        }
    }
}

void check (int t1, int t2) {
    wskt1=0; wskt2=0; licz=0;
    while (wskt1!=wsk[t1] && wskt2!=wsk[t2] && wsk[t1]>1 && wsk[t2]>1){
        //3 ify
        //printf("%d %d\n",xy[t1][wskt1],xy[t2][wskt2]);
        if (xy[t1][wskt1]>xy[t2][wskt2]) {
            wskt2++;
        }
        else if (xy[t1][wskt1]<xy[t2][wskt2]) {
            wskt1++;
        }
        else {
            licz++;
            wskt1++;
        }
    }
    licz=licz*(licz-1);
    licz=licz/2;
    wyn=wyn+licz;
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a,&b);
        if (a>0) {
            a=abs(a);
            xy[0][wsk[0]]=a;
            cxy[0][wsk[0]]=a;
            wsk[0]++;
        }
        else if (a<0) {
            a=abs(a);
            xy[1][wsk[1]]=a;
            cxy[1][wsk[1]]=a;
            wsk[1]++;
        }
        else {
            if (b>0) {
                b=abs(b);
                xy[2][wsk[2]]=b;
                cxy[2][wsk[2]]=b;
                wsk[2]++;
            }
            else if (b<0) {
                b=abs(b);
                xy[3][wsk[3]]=b;
                cxy[3][wsk[3]]=b;
                wsk[3]++;
            }
        }
    }
    if (n<4) {
        printf("%d",0);
        return 0;
    }
    for (int i=0; i<4; i++) {
        sort(xy[i],xy[i]+wsk[i]);
    }
    //printf("%f %f %f %f\n",cxy[0][0],cxy[1][0],cxy[2][0],cxy[3][0]);
    //0-px
    //1-mx
    //2-py
    //3-my
    //6x compare, px+mx, py+my, px+py, mx+my, mx+py, px+my
    check(0,2); check(1,3); check(1,2); check(0,3);
    scheck();
    printf("%lld",wyn);
    return 0;
}
