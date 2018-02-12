#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

struct option{
	int to;
	ll dist;  ll cost;
  option(int t,ll d,ll c): to(t), dist(d), cost(c)
  {}
};

struct option_cmp{
    bool operator()( option o0, option o1){
      if(o0.dist>o1.dist)return 1;
      if(o0.dist<o1.dist)return 0;
      if(o0.cost>o1.cost)return 1;
      if(o0.cost<o1.cost)return 0;
      return 0;
    }
};

int n,m;
unordered_map<string,int> sidx;
unordered_map<int,vector<ii>> g;
vector<int> v;

int main(){
	cin>>n>>m;
	sidx["English"]=0;
	for(int i=0;i<n;i++){string s;cin>>s;sidx[s]=0;}
	{int i=0;for(auto& a:sidx){a.second=i;i++;}}
	v.assign(n+1,-1);
//	for(auto& a:sidx)cout<<a.first<<" "<<a.second<<endl;
	for(int i=0;i<m;i++){
		string as,bs;ll x;cin>>as>>bs>>x;
		int a=sidx[as];int b=sidx[bs];
		if(g.count(a)==0)g[a]=vector<ii>();
		g[a].push_back(ii(b,x));
		if(g.count(b)==0)g[b]=vector<ii>();
		g[b].push_back(ii(a,x));
	}
//	for(auto& a:g){cout<<a.first<<"\t";for(auto& b:a.second)cout<<b.first<<" ";cout<<endl;}
	priority_queue<option,vector<option>,option_cmp> pq;
	ll ans=0;
	pq.push(option(sidx["English"],0,0));
	
	while(!pq.empty()){
		auto o=pq.top();
		pq.pop();
		if(v[o.to]!=-1)continue;
//		cout<<o.to<<" "<<o.cost<<endl;
		v[o.to]=o.dist;
		ans+=o.cost;
		for(auto& nb:g[o.to]){
			if(v[nb.first]!=-1)continue;
			pq.push(option(nb.first,o.dist+1,nb.second));
		}
	}
	for(auto a:v)if(a==-1){cout<<"Impossible"<<endl;return 0;}
	cout<<ans<<endl;
	
}
