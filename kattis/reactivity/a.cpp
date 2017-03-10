#include <bits/stdc++.h>
using namespace std;

// in degree, neighbours
typedef vector<pair<int, vector<int> > > adj_list;

vector<int> topological_sort(adj_list& g) {
	vector<int> ans;
	queue<int> zero;
	for (int i=0;i<g.size();i++) {
		auto p=g[i];
		if (p.first == 0) {
			zero.push(i);
		}
	}
	while (!zero.empty()) {
		if(zero.size()>1){
			cout<<"back to the lab\n";
			return ans;
		}
		int s = zero.front();
		zero.pop();
		ans.push_back(s);
		for (int n : g[s].second) {
			g[n].first--;
			if (g[n].first == 0) {
				zero.push(n);
			}
		}
	}
	if(ans.size()!=g.size()){
		cout<<"back to the lab\n";
					return ans;
	}
	for(int i:ans){
		cout<<i<<' ';
	}
	return ans;
}


int main(){
	int n,m,x,y;
	cin>>n>>m;
	adj_list g(n,pair<int,vector<int> >());
	while(m--){
		cin>>x>>y;
		g[x].second.push_back(y);
		g[y].first++;
	}
	topological_sort(g);
}