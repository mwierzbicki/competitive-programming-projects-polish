//
// Original problem statement:
// http://main.edu.pl/pl/archive/oi/20/lan
//

#include <iostream>
#include <cstdio>
using namespace std;

int prr[1000001];

int main(){
	ios_base::sync_with_stdio();
	int n,m,wyn=0;
	int dobry=0;
	long long sum=0;
	cin >> n >> m;
	int pr[m][2];
	//int prr[m];
	int ciag[n];
	//bool stop=false;
	for (int i=0; i<m; i++) {
		cin >> pr[i][0];
		sum = sum + pr[i][0];
		if (sum > n) {
			cout << 0;
			return 0;
		}
	}
	
	for (int i=0; i<m; i++) {
		cin >> pr[i][1];
		prr[pr[i][1]]=prr[pr[i][1]]+pr[i][0];
		//cout << prr[pr[i][1]] << endl;
		if(prr[pr[i][1]]==0)
			dobry++;
	}
	//cout << "3xprr[pr[i][1] powyzej \n";
	for (int i=0; i<n; i++) {
		cin >> ciag[i];
	}
	int sum2=sum;
	if (sum > n) {
		cout << 0;
		return 0;
	}
	else {
		for (int i=0; i<sum2; i++) {
			prr[ciag[i]]--;
			if (prr[ciag[i]]==-1) {
				dobry--;
			}
			if (prr[ciag[i]]==0){
				dobry++;
			}
		}
	//	printf("%d\n", dobry);
		if (m==dobry) {
			wyn++;
		}
		//if (stop==false) {
			//wyn++;
		//}
		for (int i=sum2; i<n; i++) {
			if(ciag[i]!=ciag[i-sum2]){
				prr[ciag[i]]--;
				prr[ciag[i-sum2]]++;
				if (prr[ciag[i]]==0) {
					dobry++;
				}
				if (prr[ciag[i]]==-1){
					dobry--;
				}
				if (prr[ciag[i-sum2]]==0) {
					dobry++;
				}
				if (prr[ciag[i-sum2]]==1){
					dobry--;
				}
			}
		//	printf("%d\n", dobry);
			if (m==dobry) {
				wyn++;
			}
			//}
			/*if (stop==false) {
				wyn++;
			}*/
		}
	}
	cout << wyn;
}
