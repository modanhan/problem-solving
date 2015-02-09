#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > graph;

int main() {
	int n;
	cin >> n;
	while (n != 1) {
		graph g(n, vector<int>());
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int s, t, k;
			cin >> s >> t >> k;
			s--;
			t--;
			for (int asd = 0; asd < k; asd++) {
				g[s].push_back(t);
				g[t].push_back(s);
			}
		}

		vector<int> cvs;

		queue<int> q;
		vector<bool> v(n, 0);
		q.push(0);
		v[0] = 1;
		while (!q.empty()) {
			int t = q.front();
			cvs.push_back(t);
			q.pop();
			for (int i : g[t]) {
				if (!v[i]) {
					v[i] = 1;
					q.push(i);
				}
			}
		}

		if (cvs.size() == n) {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (g[i].size() % 2 == 1) {
					ans++;
				}
			}
			cout << ans / 2 << "\n";
		} else {
		//	cout << "oh snap\n";
			int ansans = 0;
			int ans = 0;
			for (int i : cvs) {
				if (g[i].size() % 2 == 1) {
					ans++;
				}
			}
			if (ans > 2) {
				ansans += (ans - 2) / 2;
			}
			int cc=1;

			while (find(v.begin(), v.end(), 0) != v.end()) {
				ans=0;
				cc++;
				cvs.clear();
				int node = distance(v.begin(),find(v.begin(), v.end(), 0));
				q.push(node);
				v[node] = 1;
				while (!q.empty()) {
					int t = q.front();
					cvs.push_back(t);
					q.pop();
					for (int i : g[t]) {
						if (!v[i]) {
							v[i] = 1;
							q.push(i);
						}
					}
				}
				for (int i : cvs) {
					if (g[i].size() % 2 == 1) {
						ans++;
					}
				}
				if (ans > 2) {
					ansans += (ans - 2) / 2;
				}
			}

			cout << ansans+cc << "\n";
		}

		cin >> n;
	}
}
