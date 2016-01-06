#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int l;
		cin >> l;
		vector<int> v(l, 0);
		for (int i = 0; i < l; i++) {
			cin >> v[i];
		}
		int good = 1;
		if (v[0] % 4 != 1) {
		//	cout << "a";
			good = 0;
		}
		for (int i = 0; i < l - 2; i++) {
			if (v[i] / 4 == 1||v[i]/4==33) {
				if (v[i + 1] % 4 != 1) {
				//	cout << "b" << i;
					good = 0;
					break;
				}
			}
		}
		for(int i=1;i<l-1;i++){
			if(v[i-1]/4!=33&&v[i-1]/4!=1){
				if(v[i]%4!=2){
				//	cout<<"c";
					good=0;
					break;
				}
			}
		}
		if (v[l - 2] / 4 !=33&&v[l - 2] / 4 !=1) {
			if (v[l - 1] % 4 != 3) {
			//	cout << "d"<<v[l-1];
				good = 0;
			}
		}else{
			if (v[l - 1] % 4 != 0) {
						//	cout << "d"<<v[l-1];
							good = 0;
						}
		}
		if (good) {
			cout << "Case #" << t << ": Yes\n";
		} else {
			cout << "Case #" << t << ": No\n";
		}
	}
}
