#include <bits/stdc++.h>
using namespace std;

/*
 * bellman ford
 */

#define inf 10000000
typedef pair<int, int> ii;
typedef vector<vector<ii> > adj_list;

vector<int> bellman_ford(adj_list& g, int s) {
	vector<int> dist(g.size(), inf);
	dist[s] = 0;
	for (int i = 0; i < g.size() - 1; i++) {
		for (int u = 0; u < g.size(); u++) {
			for (int j = 0; j < g[u].size(); j++) {
				ii v = g[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
		}
	}
	return dist;
}

bool negative_cycle(adj_list& g, vector<int>& dist) {
	for (int u = 0; u < g.size(); u++) {
		for (int j = 0; j < g[u].size(); j++) {
			ii v = g[u][j];
			if (dist[v.first] > dist[u] + v.second) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		adj_list g(n, vector<ii>());
		while (m--) {
			int x, y, t;
			cin >> x >> y >> t;
			g[x].push_back(ii(y, t));
		}
		vector<int> dist = bellman_ford(g, 0);
		if (negative_cycle(g, dist)) {
			cout<<"possible\n";
		} else {
			cout<<"not possible\n";
		}
	}
}
