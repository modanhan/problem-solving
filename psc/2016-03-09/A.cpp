#include <bits/stdc++.h>
using namespace std;

int x[256];
int y[256];

string s1="QWERTYUIOP";
string s2="ASDFGHJKL";
string s3="ZXCVBNM";

int main(){
	for(int i=0; i<s1.size(); i++) {x[s1[i]] = 0; y[s1[i]] = i;}
	for(int i=0; i<s2.size(); i++) {x[s2[i]] = 1; y[s2[i]] = i;}
	for(int i=0; i<s3.size(); i++) {x[s3[i]] = 2; y[s3[i]] = i;}
	x[' '] = 3; y[' '] = 3;
	
	int tc; cin >> tc; cin.ignore();
	string s;
	while(getline(cin, s)){
		int res = 0;
		int xp = 0, yp = 2;
		for(int i=0; i<s.size(); i++) if(s[i]!=' '){
			res += 2*(abs(x[s[i]]-xp) + abs(y[s[i]]-yp)) + 1;
			xp = x[s[i]]; yp = y[s[i]];			
		} else res += 5;
		cout << res << '\n';
	}

	
	return 0;
}
