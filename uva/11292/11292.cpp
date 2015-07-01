#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(1){
		int ans=0;
		cin>>n>>m;
		if(n==0&&m==0){
			break;
		}
		vector<int> dragons(n,0),knights(m,0);
		for(int i=0;i<n;i++){
			cin>>dragons[i];
		}
		for(int i=0;i<m;i++){
			cin>>knights[i];
		}
		sort(dragons.begin(),dragons.end());
		sort(knights.begin(),knights.end());
		int d=0,k=0;
		for(d=0;d<n;d++){
			while(knights[k]<dragons[d]&&k<m){
				k++;
			}
			if(k>=m){
				goto bad;
			}
			ans+=knights[k];
			k++;
		}
		cout<<ans<<"\n";
		continue;
		bad:
		cout<<"Loowater is doomed!\n";
	}
}