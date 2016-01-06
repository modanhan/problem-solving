#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	while(n--){
		int d,x,s,bestpl=1000000,bestps=1000000,su=0,ans=0;
		cin>>d>>x>>s;
		while(d--){
			int c,pl,ps;cin>>c>>pl>>ps;
			bestpl=min(bestpl,pl);
			bestps=min(bestps,ps);
			ans+=c*bestpl*x;
			while(su<c*s){
				su+=80;
				ans+=bestps;
			}
			su-=c*s;
		}
		cout<<ans<<'\n';
	}
}