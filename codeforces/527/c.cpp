#include <bits/stdc++.h>
using namespace std;
int main() {
	int w, h, n;
	cin >> w >> h >> n;
	set<int> ws, hs;
	int wm = w, hm = h;
	while (n--) {
		char c;
		int p;
		cin >> c >> p;
		set<int>::iterator last;
		if (c == 'H') {
			auto it = hs.insert(p).first;
			hm = *hs.begin();
			last=it;
		} else {
			auto it = ws.insert(p).first;
			wm = *ws.begin();
			last=it;
		}
		cout << hm * wm << "\n";
	}
}
