#include <bits/stdc++.h>
using namespace std;

#define inf 1000000123

int f,s,t;
vector<vector<int> > m;
vector<int> p;

void augment(int v, int mine){
	if(v==s){
		f=mine;return;
	}else if(p[v]!=-1){
		augment(p[v],min(mine,m[p[v]][v]));
		m[p[v]][v]-=f;m[v][p[v]]+=f;
	}
}

int main(){
	int counter=1;
	int n;
	cin>>n;
	while(n){
		m.assign(n,vector<int>(n,0));
		int c;
		cin>>s>>t>>c;
		s--;t--;
		while(c--){
			int a,b,l;cin>>a>>b>>l;
			a--;b--;
			m[a][b]+=l;
			m[b][a]+=l;
		}
		int mf=0;
		while(1){
			f=0;
			vector<int> dist(n,inf);
			dist[s]=0;
			queue<int> q;q.push(s);
			p.assign(n,-1);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(u==t){
					break;
				}
				for(int i=0;i<n;i++){
					if(m[u][i]>0&&dist[i]==inf){
						dist[i]=dist[u]+1;
						q.push(i);
						p[i]=u;
					}
				}
			}
			augment(t,inf);
			if(f==0){
				break;
			}
			mf+=f;
		}
		cout<<"Network "<<counter<<"\nThe bandwidth is "<<mf<<".\n\n";
		counter++;
		cin>>n;
	}
}