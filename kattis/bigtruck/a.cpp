#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> ii;

ll n,m;
vector<ll> t;

vector<vector<ii> > g;
vector<ll> v;



int main(){
	int n;cin>>n;
	t.assign(n,0);
	g.assign(n,vector<ii>());
	v.assign(n,1000000000000);
	for(int i=0;i<n;i++)cin>>t[i];
	cin>>m;
	for(int i=0;i<m;i++){
		ll a,b,d;cin>>a>>b>>d;
		a--;b--;
		g[a].push_back(ii(b,d));
		g[b].push_back(ii(a,d));
	}
	//g[a]={(b,w),..} iff a is adjacent to b with weight w
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	//pq contains (d,v) iff it is possible to traverse to v with distance d
	pq.push(ii(100000-t[0],0));
	v[0]=100000-t[0];
	while(!pq.empty()){
		ii top=pq.top();
		pq.pop();
		if(v[top.second]<top.first)continue;
	//	cout<<top.first<<"\t"<<top.second<<endl;
		v[top.second]=top.first;
		for(ii neighbour:g[top.second]){
			ll td=v[top.second]+(neighbour.second)*100000-t[(int)(neighbour.first)];
			if(v[neighbour.first]>td)
			pq.push(ii(td,neighbour.first));
		}
	}
	//for(int i=0;i<n;i++)cout<<i<<"\t"<<v[i]/100000<<"\t"<<100000-v[i]%100000<<endl;
	if(v[n-1]==1000000000000)cout<<"impossible\n";
	else cout<<v[n-1]/100000<<" "<<100000-v[n-1]%100000<<"\n";
	
}
