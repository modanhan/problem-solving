#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> ns(n, ""), ms(m, "");
	set < string > ss;
	for (int i = 0; i < n; i++) {
		cin >> ns[i];
		ss.insert(ns[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> ms[i];
	}
	for (int i = 0; i < m; i++) {
		bool good = 0;
		if (ms[i].size() < 2000) {
			for (int si = 0; si < ms[i].size(); si++) {
				for (int asdf = 0; asdf < 3; asdf++) {
					if (ms[i][si] == 'a') {
						ms[i][si] = 'b';
					} else if (ms[i][si] == 'b') {
						ms[i][si] = 'c';
					} else if (ms[i][si] == 'c') {
						ms[i][si] = 'a';
					}
					if (asdf != 2 && ss.find(ms[i]) != ss.end()) {
						good = 1;
						break;
					}
				}
				if (good) {
					break;
				}
			}

			if (good) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

		} else {
			for(string s:ns){
				if(s.size()==ms[i].size()){
					int diff=0;
					for(int asdf=0;asdf<s.size();asdf++){
						if(s[asdf]!=ms[i][asdf]){
							diff++;
						}
						if(diff>=2){
							break;
						}
					}
					if(diff==1){
						good=1;
						break;
					}
				}
			}
			
			
			if (good) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}

	}
}
