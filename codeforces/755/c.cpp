#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vvi g;

int main(){
	cin>>n;
	g.assign(n, vi());
	for(int i=0;i<n;i++){
		int x;cin>>x;x--;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	vi visited(n,0);
	int ans=0;
	int c=0;
	for(int i=0;i<n;i++){
		if(visited[i])continue;
		bool connected=0;
		c++;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int t=q.back();q.pop();
			visited[t]=c;
			for(int nb:g[t]){
				if(!visited[nb])q.push(nb);
				if(visited[nb]!=c&&visited[nb]!=0)connected=1;
			}
		}
		if(!connected)ans++;
	}
	cout<<ans<<endl;
}
