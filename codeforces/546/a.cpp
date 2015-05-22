#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,n,w;
	cin>>k>>n>>w;
	int ans=0;
	for(int i=1;i<=w;i++){
		ans+=i*k;
	}
	ans-=n;
	if(ans>0){
		cout<<ans;
	}else{
		cout<<0;
	}
	cout<<"\n";
}