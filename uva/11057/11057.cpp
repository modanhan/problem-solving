#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,diff,ans1,ans2;
	while(cin>>n){
		diff=1000000000;
		vector<int> v(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>m;
		sort(v.begin(),v.end());
		for(auto it=v.begin();it!=v.end();it++){
			auto lb=lower_bound(v.begin(),v.end(),m-*it);
			if(*it+*lb!=m||it==lb){
				continue;
			}
			if(abs(*lb-*it)<diff){
				ans1=*it;ans2=*lb;
				diff=abs(*lb-*it);
			}
		}
		if(ans1>ans2){
			cout<<"Peter should buy books whose prices are "<<ans2<<" and "<<ans1<<".\n\n";
		}else{
			cout<<"Peter should buy books whose prices are "<<ans1<<" and "<<ans2<<".\n\n";
		}
	}
}