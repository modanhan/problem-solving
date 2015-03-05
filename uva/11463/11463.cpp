#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double> > adjmat;

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n, r;
		cin >> n >> r;
		adjmat m(n, vector<double>(n, numeric_limits<double>::infinity()));
		for (int i = 0; i < n; i++) {
			m[i][i] = 0;
		}
		
		for (int i = 0; i < r; i++) {
			int a, b;
			cin >> a >> b;
			m[a][b] = 1;
			m[b][a] = 1;
		}
		int s, e;
		cin >> s >> e;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				}
			}
		}
		
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,(int)(m[s][i]+m[i][e]));
		}
		cout<<"Case "<<(t+1)<<": "<<ans<<"\n";
	/*	for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}
}
