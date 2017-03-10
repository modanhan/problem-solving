#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sn,xn;

vector<ll> dp(60,0),dpc(60,0);

ll s(ll i){
	return (sn>>(59-i))&1;
}

ll x(ll i){
	return (xn>>(59-i))&1;
}

ll f(ll sb, ll xb, ll c){
	// no carry
	if(xb){
		// bits diff
		if(sb){
			// sum to 1
			if(c)return 0;
			else return 2;
		}else{
			// sum to 0
			if(c)return 0;
			else return 0;
		}
	}else{
		// bits same
		if(sb){
			// sum to 1
			if(c)return 1;
			else return 0;
		}else{
			// sum to 0
			if(c)return 0;
			else return 1;
		}
	}
}

ll fc(ll sb, ll xb, ll c){
	// always carry
	if(xb){
		// bits diff
		if(sb){
			// sum to 1
			if(c)return 0;
			else return 0;
		}else{
			// sum to 0
			if(c)return 2;
			else return 0;
		}
	}else{
		// bits same
		if(sb){
			// sum to 1
			if(c)return 1;
			else return 0;
		}else{
			// sum to 0
			if(c)return 0;
			else return 1;
		}
	}
}

int stupid(){
	int ans=0;
	for(int i=1;i<sn;i++){
		int j=sn-i;
		if((i^j)==xn)ans++;
	}
	return ans;
}

int main() {
	cin>>sn>>xn;
	dp[0]=f(s(0),x(0),0);
	for(int i=1;i<60;i++){
		dp[i]=f(s(i),x(i),0)*dp[i-1]+fc(s(i),x(i),0)*dpc[i-1];
		dpc[i]=f(s(i),x(i),1)*dp[i-1]+fc(s(i),x(i),1)*dpc[i-1];
	}
	/*
	for(int i=50;i<60;i++){
		cout<<s(i)<<" ";
	}cout<<endl;
	for(int i=50;i<60;i++){
		cout<<x(i)<<" ";
	}cout<<endl;
	for(int i=50;i<60;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;
	for(int i=50;i<60;i++){
		cout<<dpc[i]<<" ";
	}cout<<endl;
	*/
	if(sn==xn){
		cout<<dp.back()-2<<endl;
	}else{
		cout<<dp.back()<<endl;
	}
//	cout<<stupid()<<endl;
}
