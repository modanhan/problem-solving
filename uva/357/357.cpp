#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
typedef long long ll;
int main(){
	ll coins[5]={1,5,10,25,50};
	vector<vector<ll> > dp(5,vector<ll>(40000,0));
	for(ll i=0;i<5;i++){
		dp[i][0]=1;
	}
	for(ll i=0;i<35000;i++){
		dp[0][i]=1;
	}
	for(ll i=1;i<5;i++){
			for(ll j=1;j<35000;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=coins[i]){
					dp[i][j]+=dp[i][j-coins[i]];
				}
			}
		}
	ll x;
	while(cin>>x){
		if(dp.back()[x]!=1){
			cout<<"There are "<<dp.back()[x]<<" ways to produce "<<x<<" cents change.\n";
		}else{
			cout<<"There is only 1 way to produce "<<x<<" cents change.\n";
		}
	}
}
=======

typedef long long ll;

int main() {
	ll x, c[5] = { 1, 5, 10, 25, 50 };
	vector<ll> dp(30001, 0);
	dp[0] = 1;
	for (int i = 0; i < 5; i++) {
		for (int m = 0; m < 30001; m++) {
			if (m >= c[i]) {
				dp[m] += dp[m - c[i]];
			}
		}
	}
	while (cin >> x) {
		if (dp[x] == 1) {
			cout << "There is only 1 way to produce " << x
					<< " cents change.\n";
		} else {
			cout << "There are " << dp[x] << " ways to produce " << x
					<< " cents change.\n";
		}

	}
}
>>>>>>> 43275328949b1b761e5a42f53c9de7c8c55229ea
