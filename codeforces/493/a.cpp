#include <bits/stdc++.h>
using namespace std;

int main() {
	string h, a;
	cin >> h >> a;
	int n;
	cin >> n;

	vector < pair<int, bool> > hv(200, pair<int, bool>(0, false));
	vector < pair<int, bool> > av(200, pair<int, bool>(0, false));

	for (int i = 0; i < n; i++) {
		int x, p;
		char t, c;
		cin >> x >> t >> p >> c;
		if (t == 'h') {
			if (c == 'y') {
				hv[p].first++;
			} else {
				hv[p].first += 2;
			}
			if (hv[p].first >= 2 && !hv[p].second) {
				cout << h << " " << p << " " << x << "\n";
				hv[p].second = true;
			}
		} else {
			if (c == 'y') {
				av[p].first++;
			} else {
				av[p].first += 2;
			}
			if (av[p].first >= 2 && !av[p].second) {
				cout << a << " " << p << " " << x << "\n";
				av[p].second = true;
			}
		}
	}
}
