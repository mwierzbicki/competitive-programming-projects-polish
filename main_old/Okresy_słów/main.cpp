//
// Original problem statement:
// http://main.edu.pl/pl/archive/oi/13/okr
//

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio();
	int a,t;
	long long wynik=0;
	string str;
	cin >> a >> str;
	int tab[a+1],tabd[a+1];
	tab[0]=-1;
	t=-1;
	/*for (int i=1; i<=a; i++) {
		while 
	}*/
  	for (int j=1; j<=a; j++)
  	{
  		while(t>-1 && str[j-1]!=str[t+1-1]) {
  			t=tab[t];
  		}
  		tab[j]=t+1;
  		t=tab[j];
  		/*t++;
  		tab[j]=t;*/
  	}

  	tabd[1]=1;
  	for (int i=1; i<=a; i++) {
		if (tab[i]==0) {
			tabd[i]=i;
		}
		else {
			tabd[i]=tabd[tab[i]];
		}
		//cout << "tabd od i przed dodaniem: " << tabd[i] << " i: " << i << " a: " << a << endl;
  		wynik = wynik + i - tabd[i];
  	}
  	/*for(int i=1; i<=a; i++)
  	{
    	cout << tabd[i] << " ";
  	}*/
  	cout << wynik;
}