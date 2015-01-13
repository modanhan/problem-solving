#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> y >> x;
	vector < string > v;
	for (int i = 0; i < y; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	if (y == 1) {
		cout << "0\n";
		return 0;
	}

	int ans = 0;
	while (1) {
		bool good=1;
		for (int i = 1; i < y; i++) {
			if (v[i - 1] > v[i]) {
		//		cout<<v[i-1]<<v[i]<<"\n";
				good=0;
				break;
			}
		}
		if(good){
			break;
		}
		int badi=-1;
		for (int j = 0; j < x; j++) {
			for (int i = 1; i < y; i++) {
				if (v[i - 1][j] > v[i][j]) {
					badi=j;
					break;
				}
			}
			if(badi!=-1){
				break;
			}
		}
		for(auto s=v.begin();s!=v.end();s++){
			s->erase((s->begin()+badi));
		//	cout<<*s<<"\n";
		//	cout<<s<<badi<<"\n";
		}
		ans++;
	}
	cout << ans << "\n";
}
