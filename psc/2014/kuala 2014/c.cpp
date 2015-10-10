#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
	for(int tc=1;tc<=t;tc++){
		int a,b;cin>>a>>b;
		string s;cin>>s;
		vector<vector<bool> > m(200,vector<bool>(200,0));
		vector<vector<bool> > vt(200,vector<bool>(200,0));
		int x=a,y=b;
		int d=0;
		m[x][y]=1;
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='F'){
				x+=dx[d%4];
				y+=dy[d%4];
				if(m[x][y]){
					if(!vt[x][y]){
						vt[x][y]=1;
						ans++;
					}
				}
				m[x][y]=1;
			}else if(s[i]=='R'){
				d++;
			}else{
				d--;
				if(d<0){
					d+=4;
				}
			}
		}
		cout<<"Case #"<<tc<<": "<<x<<" "<<y<<" "<<ans<<"\n";
	}
}