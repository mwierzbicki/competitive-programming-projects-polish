//
//  Original problem statement:
//  http://main.edu.pl/pl/archive/oig/2/min
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int n;
	long long k;
	scanf("%d %lld",&n,&k);
	long long tab[n];
	for (int i=0; i<n; i++) {
		scanf("%lld",&tab[i]);
	}
	sort(tab, tab+n);
	for (long long i=k; i<=1000000000000000000; i=i+k) {
		if (!binary_search(tab, tab+n, i)) {
			printf("%lld",i);
			return 0;
		}
	}
}