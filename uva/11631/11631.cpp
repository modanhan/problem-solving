#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> ppiii;

struct uf {
	vector<int> p, r;
	uf(int n) {
		r.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	int find(int i) {
		return p[i] == i ? i : find(p[i]);
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	void u(int i, int j) {
		if (!same(i, j)) {
			int x = find(i), y = find(j);
			if (r[x] > r[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (r[x] == r[y]) {
					r[y]++;
				}
			}
		}
	}
};

vector<ppiii> edges;

bool cmp(ppiii e1, ppiii e2) {
	return e1.second < e2.second;
}

int main() {
	int x, y;
	cin >> x >> y;
	do {
		int total = 0;
		edges.clear();
		while (y--) {
			int a, b, c;
			cin >> a >> b >> c;
			pair<int, int> p(a, b);
			ppiii ugh(p,c);
			edges.push_back(ugh);
			total += c;
		}
		sort(edges.begin(), edges.end(), cmp);
		uf dsu(x);
		int ans = 0;
		for (auto p : edges) {
			if (!dsu.same(p.first.first, p.first.second)) {
				dsu.u(p.first.first, p.first.second);
				ans += p.second;
			}
		}
		cout << (total - ans) << "\n";
		cin >> x >> y;
	} while (x != 0 && y != 0);
	return 0;
}
