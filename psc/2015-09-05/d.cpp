#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	for(int t=1;t<=n;t++){
		int r,c;cin>>r>>c;
	//	vector<vector<int> > m(r,vector<int>(c));
		int ans=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
			//	cin>>m[i][j];
				int x;cin>>x;
				if((i+j)%2){
					ans+=x;
				}else{
					ans-=x;
				}
			}
		}
		if(ans){
			cout<<"Case #"<<t<<": NO\n\n";
		}else{
			cout<<"Case #"<<t<<": YES\n\n";
		}
		
	}
}