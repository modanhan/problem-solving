#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // weight, node
typedef vector<vector<ii> > adj_list; // node, weight

int n,m,q,s;

int main(){
	while(1){
		cin>>n>>m>>q>>s;
		if(n==0)break;
		
		adj_list g(n, vector<ii>());
		for(int i=0;i<m;i++){
			int u,v,w;cin>>u>>v>>w;
			g[u].push_back(ii(v,w));
		//	g[v].push_back(ii(u,w));
		}
		
		vector<int> dist(g.size(), 1000000000);
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
		for(int i=0;i<q;i++){
			int u;cin>>u;
			if(dist[u]!=1000000000)cout<<dist[u]<<endl;
			else cout<<"Impossible\n";
		}
		cout<<endl;
		
	}
}
