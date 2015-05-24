#include <bits/stdc++.h>
using namespace std;

vector<int> v,parent;

void p(int i){
	if(i==-1){
		return;
	}
	p(parent[i]);
	cout<<v[i]<<"\n";
}

int main(){
	int x;
	
	while(cin>>x){
		v.push_back(x);
	}
	int n=v.size(),max=1,last=0;
	vector<int> dp(n,1);
	parent.resize(n,-1);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[i]>v[j]){
				if(dp[i]<=dp[j]+1){
					dp[i]=dp[j]+1;
					parent[i]=j;
				}
			}
		}
		if(dp[i]>=max){
			max=dp[i];
			last=i;
		}
	}

	cout<<max<<"\n-\n";
	p(last);
	
}