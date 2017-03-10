#include <bits/stdc++.h>
using namespace std;

int n, m, id = 1;
vector<vector<int> > g, ans, ids;
map<int, int> mp;

int dfs1(int i, int j) {
	if (i < 0 || i >= n)
		return 0;
	if (j < 0 || j >= m)
		return 0;
	int a = 0;
	if (g[i][j] == 0) {
		a = 1;
		g[i][j] = 1;
		return dfs1(i + 1, j) + dfs1(i - 1, j) + dfs1(i, j + 1) + dfs1(i, j - 1)
				+ a;
	}
	return 0;
}

void dfs2(int i, int j, int v) {
	if (i < 0 || i >= n)
		return;
	if (j < 0 || j >= m)
		return;
	if (g[i][j] == 1) {
		g[i][j] = 2;
		ans[i][j] = v;
		ids[i][j] = id;
		dfs2(i + 1, j, v);
		dfs2(i - 1, j, v);
		dfs2(i, j + 1, v);
		dfs2(i, j - 1, v);
	}
}

void get(int i, int j) {
	if (i < 0 || i >= n)
		return;
	if (j < 0 || j >= m)
		return;
	mp[ids[i][j]] = ans[i][j];
}

int main() {
	cin >> n >> m;
	g.assign(n, vector<int>(m, 0));
	ans.assign(n, vector<int>(m, 0));
	ids.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			g[i][j] = s[j] == '.' ? 0 : -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 0) {
				int v = dfs1(i, j) % 10;
				dfs2(i, j, v);
				id++;
			}
//			cout << ans[i][j];
		}
//		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == -1) {
				mp.clear();
				get(i-1,j);
				get(i+1,j);
				get(i,j-1);
				get(i,j+1);
				int fans=0;
				for(auto p:mp){
					fans+=p.second;
				}
				cout<<(fans+1)%10;
			}else cout<<'.';
		}cout<<endl;
	}
}

