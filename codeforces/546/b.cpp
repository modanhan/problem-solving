#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> v(7000,0);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v[x]++;
	}
	int ans=0;
	for(int i=0;i<7000;i++){
		int j=i+1;
		while(v[i]>1){
			for(;j<7000;j++){
				if(v[j]==0){
					v[j]++;
					v[i]--;
					ans+=j-i;
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}