#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii> > graph;

vector<int> dijkstra(int s, graph g) {
	vector<int> dist(g.size(), 0x7fffffff);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) {
			continue;
		}
		for (int j = 0; j < g[u].size(); j++) {
			ii v = g[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return dist;
}

int main() {
	int N;
	cin >> N;
	for (int asdf = 0; asdf < N; asdf++) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		graph g(n, vector<ii>());
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back(ii(b, c));
			g[b].push_back(ii(a, c));
		}
		vector<int> ans = dijkstra(s, g);
		if (ans[t] >= 0x7fffffff) {
			cout << "Case #" << (asdf + 1) << ": unreachable" << "\n";
		} else {
			cout << "Case #" << (asdf + 1) << ": " << ans[t] << "\n";
		}

	}
}
