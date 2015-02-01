#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		int v;cin>>v;
		set<int> s;
		int random=0;
		vector<vector<int> > g(120,vector<int>());
		vector<int> d(120,0);
		for(int i=0;i<v;i++){
			int a,b;cin>>a>>b;
			random=a;
			g[a].push_back(b);
			g[b].push_back(a);
			d[a]++;
			d[b]++;
			s.insert(a);
			s.insert(b);
		}
		bool f=0;
		for(int i=0;i<111;i++){
			if(d[i]%2){
				f=1;
				break;
			}
		}
		if(f){
			cout<<"Case #"<<t<<": No\n";
			continue;
		}
		stack<int> q;
		s.erase(random);
		q.push(random);
		while(!q.empty()){
			int t=q.top();
			q.pop();
			for(int i:g[t]){
				if(s.find(i)!=s.end()){
					s.erase(i);
					q.push(i);
				}
			}
		}
		if(!s.empty()){
			cout<<"Case #"<<t<<": No\n";
			continue;
		}
		cout<<"Case #"<<t<<": Yes\n";
		
	}
}