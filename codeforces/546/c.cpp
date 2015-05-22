
#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	int n, ka, kb;
	cin >> n >> ka;
	queue<int> a, b;
	while (ka--) {
		int x;
		cin >> x;
		a.push(x);
	}
	cin >> kb;
	while (kb--) {
		int x;
		cin >> x;
		b.push(x);
	}
	set < pair<queue<int>,queue<int> > > s;
	int ans = 0, win = 0;
	while (1) {
		if (s.find(pair<queue<int>,queue<int> >(a,b)) != s.end()) {
			ans=-1;break;
		}
		s.insert(pair<queue<int>,queue<int> >(a,b));
		int at = a.front(), bt = b.front();
		a.pop();
		b.pop();
		if (at > bt) {
			a.push(bt);
			a.push(at);
		} else {
			b.push(at);
			b.push(bt);
		}
		ans++;
		if (a.empty()) {
			win = 2;
			break;
		}
		if(b.empty()){
			win=1;
			break;
		}

	}
	if (ans == -1) {
		cout << "-1\n";
	} else {
		cout << ans << " " << win << "\n";
	}
}
