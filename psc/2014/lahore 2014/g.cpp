#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int d, r, m;
		cin >> d >> r >> m;
		vector<int> v(1, 1);
		m--;
		while (m--) {
				for (int i : v) {
			 cerr << i << " ";
			 }
			 cerr << "\n";
			int rc = 0;
			int pc = 0;
			while (find(v.begin(), v.end(), d) != v.end()) {
				auto it=find(v.begin(), v.end(), d);
				v.erase(it);
				if(*it<=r){
				pc++;}
			}
			for (int i = 0; i < v.size(); i++) {
				if (v[i] > 1 && v[i] <= r) {
					rc++;
				}
				v[i]++;
				if(v[i]>d){
					v[i]=d;
				}
			}
			while (rc--) {
				v.push_back(1);
			}
			while (pc--) {
				v.push_back(1);
			}
		}	
		for (int i : v) {
		 cerr << i << " ";
		 }
		 cerr << "\n";
		cout << "Case #" << t << ": " << v.size() << "\n";
	}
}
