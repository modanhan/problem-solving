#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;cin>>tc;
	while(tc--){
		int l1,a1,l2,a2,lt,at;
		cin>>l1>>a1>>l2>>a2>>lt>>at;
		int n1=1, c=0, ans=-1, ans2=-1;
		while(1){
			int ltl=lt-n1*l1, atl=at-n1*a1;
			if(ltl<=0||atl<=0)break;
			if(ltl/l2!=atl/a2)goto bad;
			if(ltl/l2<1)goto bad;
			if(ltl%l2)goto bad;
			if(atl%a2)goto bad;
			ans=n1;ans2=ltl/l2;
			c++;
			if(c>1)break;
			bad: n1++;
		}
		if(c==1)cout<<ans<<' '<<ans2<<endl;
		else cout<<"?\n";
	}

}
