#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	string a;
	getline(cin, a);
	string vowels="aeiouAEIOU";
	while (t--){
		string l;
		getline(cin, l);
		int vnum = 0, cnum = 0;
		for (char c : l){
			bool v = 0;
			for (char x : vowels){
				if (x == c){
					vnum++;
					v = 1;
					break;
				}
			}
			if (!v&&c!=' '){
				cnum++;
			}
		}
		cout << cnum << ' ' << vnum << '\n';
	}
}
