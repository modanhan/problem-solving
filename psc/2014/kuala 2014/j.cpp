#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		long int ah, bh;
		cin >> hex >> ah;
		//	cout<<hex<<ah;
		cin >> hex >> bh;
		if (ah == bh) {
			cout << "Case #" << tc << ": 0 Any\n";
			continue;
		}
		queue<bool> a, b;
		for (int i = 0; i < 32; i++) {
			a.push((ah >> i) & 1);
			b.push((bh >> i) & 1);
		}
	/*			while(!a.empty()){
		 cout<<a.front();
		 a.pop();
		 }cout<<"\n";
		 while(!b.empty()){
		 cout<<b.front();
		 b.pop();
		 }*/
		 
		// return 0;

		int ans = -1;
		queue<bool> c = a;
		for (int i = 0; i < 32; i++) {
			c.push(c.front());
			c.pop();
			if (c == b) {
				ans = i + 1;
				break;
			}
		}
		if (ans == -1) {
			cout << "Case #" << tc << ": Not possible\n";
			continue;
		}
		c = b;
		string dir = " Right\n";
		for (int i = 0; i < 32; i++) {
			c.push(c.front());
			c.pop();
			if (c == a) {
				if (i == ans-1) {
					dir = " Any\n";
				} else if (i < ans-1) {
					dir = " Left\n";
					ans = i + 1;
				}
				break;
			}
		}

		cout << "Case #" << tc << ": " << ans << dir;
	}
}
