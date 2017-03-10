#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<int> vn,vm, dpn, dpm;

int main(){
	cin>>n;
	vn.assign(n,0);
	for(int i=0;i<n;i++)cin>>vn[i];

	cin>>m;
	vm.assign(m,0);
	for(int i=0;i<m;i++)cin>>vm[i];

	int asdf=100100;
	// dp[i] = min number of elements sum up to i
	dpn.assign(asdf,200);
	dpm.assign(asdf,200);

	if(n==0||m==0){cout<<"impossible\n";return 0;}

	dpn[0]=0;
	dpm[0]=0;
	for(int j=0;j<n;j++){for(int i=asdf-1;i>=0;i--){
		if(dpn[i]!=200)dpn[i+vn[j]]=min(dpn[i+vn[j]], dpn[i]+1);
	}}
	for(int j=0;j<m;j++){for(int i=asdf-1;i>=0;i--){
        if(dpm[i]!=200)dpm[i+vm[j]]=min(dpm[i+vm[j]], dpm[i]+1);
    }}
	int ans=98765432;
	for(int i=1;i<asdf;i++){
		ans=min(ans, dpn[i]+dpm[i]);
	}
	if(ans>200)cout<<"impossible\n";
	else cout<<ans<<endl;
}
