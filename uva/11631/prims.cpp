#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<ii> > adj_list;

int prim(adj_list& g, int s) {
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	vector<bool> v(g.size(), 0);
	pq.push(ii(0, s));
	int ans = 0;
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int w = front.first, u = front.second;
		if (v[u])
			continue;
		ans += w;
		v[u] = 1;
		for (ii x : g[u]) {
			if (!v[x.second]) {
				pq.push(x);
			}
		}
	}
	return ans;
}

int main() {
	int m, n;
	while (1) {
		int total = 0;
		cin >> n >> m;
		if (m == 0 && n == 0) {
			break;
		}
		adj_list g(n, vector<ii>());
		while (m--) {
			int x, y, z;
			cin >> x >> y >> z;
			g[x].push_back(ii(z, y));
			g[y].push_back(ii(z, x));
			total += z;
		}

		cout << total - prim(g, 0) << '\n';
	}
}
