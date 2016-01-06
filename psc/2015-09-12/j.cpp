#include <bits/stdc++.h>
using namespace std;

double f;
int s,t;
vector<vector<double> > m;
vector<int> p;

void augment(int v, double mine) {
	if (v == s) {
		f = mine;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(mine, m[p[v]][v]));
		m[p[v]][v] -= f;
		m[v][p[v]] += f;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		double td=0;
		m.assign(n + 2, vector<double>(n + 2, 0));
		int s = 0, t = n + 1;
		for (int i = 1; i < n +1; i++) {
			double d;
			cin >> d;
			m[s][i] = d;
			m[i][s] = d;
			td+=d;
		}
		for (int i = 1; i < n +1; i++) {
			double d;
			cin >> d;
			m[t][i] = d;
			m[i][t] = d;
			td+=d;
		}
		for(int i=1;i<n+1;i++){
			for(int j=1;j<n+1;j++){
				double d;cin>>d;
				m[i][j]+=d;
				m[j][i]+=d;
				td+=d;
			}
		}
		double mf = 0;
		while (1) {
			f = 0;
			vector<int> dist(n+2, 10000);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(n+2, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t) {
					break;
				}
				for (int i = 0; i < n+2; i++) {
					if (m[u][i] > 0 && dist[i] == 10000) {
						dist[i] = dist[u] + 1;
						q.push(i);
						p[i] = u;
					}
				}
			}
			augment(t, 10000);
			if (f == 0) {
				break;
			}
			mf += f;
		}
		printf("%.2f\n",td-mf);
	}
}
