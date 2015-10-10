#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int mx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 }, my[8] = { 1, 1, 1, 0, -1, -1, -1,
			0 };
	int x0, y0, x1, y1, n;
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	set<ii> s;

	map<ii, int> dist;
	while (n--) {
		int r, a, b;
		cin >> r >> a >> b;
		for (int i = a; i <= b; i++) {
			ii t(r, i);
			s.insert(t);
			dist[t] = -1;
		}
	}

	queue<ii> q;
	ii final(x1, y1);
	
	q.push(ii(x0, y0));
	dist[ii(x0, y0)] = 0;
	while (!q.empty()) {
		ii t = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			ii u(t.first + mx[i], t.second + my[i]);
			if (s.find(u) != s.end() && dist[u] == -1) {
				dist[u] = dist[t] + 1;
				q.push(u);
				if (u == final) {
					goto done;
				}
			}
		}
	}
	done: cout << dist[final];
}
