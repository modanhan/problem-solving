#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, string> m;
	m['a'] = "2";
	m['b'] = "22";
	m['c'] = "222";
	m['d'] = "3";
	m['e'] = "33";
	m['f'] = "333";
	m['g'] = "4";
	m['h'] = "44";
	m['i'] = "444";
	m['j'] = "5";
	m['k'] = "55";
	m['l'] = "555";
	m['m'] = "6";
	m['n'] = "66";
	m['o'] = "666";
	m['p'] = "7";
	m['q'] = "77";
	m['r'] = "777";
	m['s'] = "7777";
	m['t'] = "8";
	m['u'] = "88";
	m['v'] = "888";
	m['w'] = "9";
	m['x'] = "99";
	m['y'] = "999";
	m['z'] = "9999";
	m[' '] = "0";

	int t;
	cin >> t;
	string asdf;getline(cin,asdf);
	for (int T = 1; T <= t; T++) {
		string s;
		getline(cin, s);
		string x=".";
		cout << "Case #" << T << ": ";
		for(char c:s){
			if(m[c][0]==x[0]){
				cout<<' '<<m[c];
				x=""+m[c];
			}else{
				cout<<m[c];
				x=""+m[c];
			}
		}

		
		cout << "\n";
	}
}
