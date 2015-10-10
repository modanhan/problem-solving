#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector < pair<ll, ll> > v(n, pair<ll, ll>(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	map<ll, map<ll, vector<ll> > > dp;
	for (int i = -200; i <= 200; i++) {
		map<ll, vector<ll> > m;
		dp[i] = m;
		for (int j = -200; j <= 200; j++) {
			vector<ll> v(n, 0);
			dp[i][j] = v;
		}
	}
	//vector (x,y) using up to index i has dp[x][y][i] ways
	dp[v[0].first][v[0].second][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int x = -200; x <= 200; x++) {
			for (int y = -200; y <= 200; y++) {
				if (dp[x][y][i - 1]) {
					dp[x][y][i] += dp[x][y][i - 1];
					if((x + v[i].first<=200)&&(y + v[i].second<=200))
					dp[x + v[i].first][y + v[i].second][i] += dp[x][y][i - 1];
				}
			}
		}
		dp[v[i].first][v[i].second][i]++;
	}
	cout << dp[0][0][n - 1]<<'\n';
}
