#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<string> v(n,string());
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		//try to make row i clean
		vector<string> t=v;
		for(int j=0;j<n;j++){
			if(v[i][j]=='0'){
				//item at column j dirty
				for(int k=0;k<n;k++){
					if(t[k][j]=='0'){
						t[k][j]='1';
					}else{
						t[k][j]='0';
					}
				}
			}
		}
		int tans=0;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(t[x][y]=='0'){
					goto bad;
				}
			}
			tans++;
			bad:;
		}
		ans=max(ans,tans);
	}
	cout<<ans<<"\n";
}