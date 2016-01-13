#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii> > adj_list;
adj_list g;
int p, t;
int p1, p2, l;

vector<int> dijkstra(int s) {
	vector<int> dist(p,1000000000);
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
	while (cin >> p >> t) {
		g.assign(p, vector<ii>());
	
		for (int i = 0; i < t; i++) {
			cin >> p1 >> p2 >> l;
			g[p1].push_back(ii(p2, l));
			g[p2].push_back(ii(p1, l));
		}
		int ans=0;
		vector<int> d1=dijkstra(0);
		vector<int> d2=dijkstra(p-1);
		for(int i=0;i<p;i++){
			for(ii x:g[i]){
				if(d1[i]+d2[x.first]+x.second==d1[p-1])ans+=x.second;
			}
		}
		cout<<ans*2<<'\n';
	}
}
