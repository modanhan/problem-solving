#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

/*
 * generate path from a convex hull
 */

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ii> v;
		int minx = 2000000000, miny = 2000000000, maxx = -2000000000, maxy =
				-2000000000;
		while (n--) {
			char c;
			ii i;
			cin >> i.second >> i.first >> c;
			if (c == 'Y') {
				minx = min(minx, i.second);
				miny = min(miny, i.first);
				maxx = max(maxx, i.second);
				maxy = max(maxy, i.first);
				v.push_back(i);
			}
		}
		sort(v.begin(), v.end());
		int c = 0;
		cout << v[c].second << ' ' << v[c].first << '\n';
		// going down
		for (int i = c; i < n; i++) {
			if (v[i].first < v[c].first) {
				c = i;
				cout << v[c].second << ' ' << v[c].first << '\n';
			}
		}
		// going right
		for (int i = c; i < n; i++) {
			if (v[i].first < v[c].first) {
				c = i;
				cout << v[c].second << ' ' << v[c].first << '\n';
			}
		}
	}
}
