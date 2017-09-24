//
// Original problem statement:
// http://main.edu.pl/pl/archive/pa/2014/mat
//

#include <iostream>
#include <string>

using namespace std;

int main () {
	int j=0,min=1000000000,m;
	string s;
	char tempp;
	bool stop=true;
	cin >> s;
	while (j<s.length() && s[j] == '*') {
		j++;
	}
	if (j==s.length()){
		cout << 1;
		return 0;
	}
	tempp = s[j];
	for(int i=0; i<s.length(); i++)
	{
		if (tempp != s[i] && s[i] != '*')
		{
			stop = false;
			break;
		}
	}
	if (stop == true)
	{
		cout << 1;
		return 0;
	}
	for (int i=j; i<s.length(); i++) {
		if (s[i] == tempp) {
			m=1;
		}
		else if (s[i]=='*') {
			m++;
		}
		else {
			if (min>m) {
				min=m;
			}
			m=1;
			tempp=s[i];	
		}
		
	}
	cout << s.length()-min+1;	
}