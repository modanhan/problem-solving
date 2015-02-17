#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	vector < pair<int, int> > v(n, pair<int, int>(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].first -= x;
		v[i].second -= y;
	}
	vector<bool> visited(n, 0);
	for (int i = 0; i < n; i++) {
		if (v[i].first == 0 && v[i].second == 0) {
			visited[i] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			if (v[i].first != 0) {
				double m = (double) v[i].second / (double) v[i].first;
				for (int j = i; j < n; j++) {
					if (m == (double) v[j].second / (double) v[j].first) {
						visited[j] = 1;
					}
				}
			} else {
				for (int j = i; j < n; j++) {
					if (v[j].first == 0) {
						visited[j] = 1;
					}
				}
			}
			ans++;
		}
	}
	if (ans == 0) {
		ans = 1;
	}
	cout << ans << '\n';
}
