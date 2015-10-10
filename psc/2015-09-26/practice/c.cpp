#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll u = 10000000;
bitset<10000001> bs;
vector<ll> lpf;

void sieve() {
	lpf.assign(10000000,0);
	lpf[1]=1;
	u++;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < u; i++) {
		if (bs[i]) {
			lpf[i]=i;
			for (ll j = i * 2; j < u; j += i) {
				bs[j] = 0;
				lpf[j]=max(lpf[j],i);
			}
		}
	}
}

int main(){
	sieve();
	int n;while(cin>>n){
//		cout<<lpf[n]<<"\n";
		int ans=0;
		while(n>0){
			n-=lpf[n];
			ans++;
		}
		cout<<ans<<"\n";
	}
}