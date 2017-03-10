#include <bits/stdc++.h>
using namespace std;

int masks[]={416,464,200,308,186,89,38,23,11};

int toint(string a, string b, string c){
	int ans=0;
	for(int i=0;i<3;i++){
		if(a[i]=='*')ans|=1<<(i+6);
		if(b[i]=='*')ans|=1<<(i+3);
		if(c[i]=='*')ans|=1<<(i);
	}
	return ans;
}

void bfs(int x){
	vector<int> dist(1000000,-1);
	queue<int> q;
	dist[x]=0;
	q.push(x);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int m:masks){
			int n=m^t;
			if(dist[n]==-1){
				dist[n]=dist[t]+1;
				q.push(n);
			}
		}
	}
	cout<<dist[0]<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		string a,b,c;cin>>a>>b>>c;
		int x=toint(a,b,c);
		bfs(x);
	}
}