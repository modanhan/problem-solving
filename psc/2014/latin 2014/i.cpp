#include <bits/stdc++.h>
using namespace std;

void removeFriends(int node, vector<int> &parent, vector<bool> &friends,
		vector<bool> &checked);

int main() {
	int f, n;
	cin >> f >> n;
	vector < vector<pair<int, int> > > g(f + 1, vector<pair<int, int> >());
	for (int i = 0; i < f - 1; i++) {
		int asdf, sdf, df;
		cin >> asdf >> sdf >> df;
		pair<int, int> p(sdf, df);
		g[asdf].push_back(p);
	}

	vector<bool> friends(f + 1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		friends[x] = 1;
	}

	vector<int> cost(f + 1, 0);

	queue<int> q;
	vector<bool> v(f + 1, 0);
	v[1] = 1;
	q.push(1);
	vector<int> ancestor(f + 1);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (pair<int, int> nasdf : g[t]) {
			if (!v[nasdf.first]) {
				cost[nasdf.first] = cost[t] + nasdf.second;
				v[nasdf.first] = 1;
				q.push(nasdf.first);
				ancestor[nasdf.first] = t;
			}
		}
	}

	vector<bool> checked(f + 1, 0);

	for (int i = 0; i < f + 1; i++) {
		if (friends[i]) {
			removeFriends(i, ancestor, friends, checked);
		}
	}
	int ans = 0;
	int maxx = 0;
	for (int i = 0; i < f + 1; i++) {
		if (friends[i]) {
			maxx = max(maxx, cost[i]);
			ans += cost[i];
		}
	}
	cout << ans - maxx << "\n";
}

void removeFriends(int node, vector<int> &parent, vector<bool> &friends,
		vector<bool> &checked) {
	if (parent[node] == 1 || checked[node])
		return;
	else {
		checked[node] = 1;
		friends[parent[node]] = 0;
		removeFriends(parent[node], parent, friends, checked);
	}
}

