#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0;
	string a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		int diff=abs(a[i]-b[i]);
		if(diff>5){
			diff=10-diff;
		}
		ans+=diff;
	}
	cout<<ans<<"\n";
}