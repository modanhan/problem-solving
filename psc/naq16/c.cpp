#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,m;
vector<int> t;
vector<vector<ii> > g;

int main(){
	cin>>n;
	t.assign(n,0);
	g.assign(n,vector<ii>());
	for(int i=0;i<n;i++)cin>>t[i];
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b,d;cin>>a>>b>>d;
		a--;b--;
		g[a].push_back(ii(b,d));
		g[b].push_back(ii(a,d));
	}

	vector<int> dist(n, 1000000000);
	vector<int> mitem(n,0);
	dist[0] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	pq.push(iii(0, ii(0,0)));
	while (!pq.empty()) {
		iii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second.first, item=front.second.second;
		if (d > dist[u]) {
			continue;
		}
		mitem[u]=max(mitem[u], item+t[u]);
		for (int j = 0; j < g[u].size(); j++) {
			ii v = g[u][j];
			if (dist[u] + v.second <= dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(iii(dist[v.first], ii(v.first, mitem[u])));
			}
		}
	}
	if(dist.back()==1000000000)cout<<"impossible"<<endl;
	else cout<<dist.back()<<' '<<mitem.back()<<endl;
}
