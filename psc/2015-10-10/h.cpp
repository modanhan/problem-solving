#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<pair<int,double>,ii> idii;
int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0)break;
		vector<ii> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i].second>>v[i].first;
		}
		sort(v.begin(),v.end());
		// v[0] is the origin/root/whatevs
		double ans=0;
		
		priority_queue<idii,vector<idii>,greater<idii> > pq;
		set<ii> visited;
		pq.push(idii(pair<int,double>(v[0].first,0),v[0]));
		
		while(!pq.empty()){
			double w=pq.top().first.second;
			ii t=pq.top().second;
			pq.pop();
			if(visited.find(t)!=visited.end())continue;
			visited.insert(t);
			ans+=w;
			for(ii i:v){
				if(t.first<=i.first){
					double d=sqrt((t.first-i.first)*(t.first-i.first)
							+(t.second-i.second)*(t.second-i.second));
					pq.push(idii(pair<int,double>(i.first,d),i));
				}
			}
		}
		
		printf("%.2f\n",ans);
	}
}