#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll u = 200000;
bitset<200001> bs;
vector<ll> primes;

void sieve() {
	u++;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < u; i++) {
		if (bs[i]) {
			for (ll j = i * i; j < u; j += i) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		auto it=lower_bound(primes.begin(),primes.end(),x);
		cout<<"Input value: "<<x<<"\n";
		if(*it==x){
			cout<<"Would you believe it; it is a prime!\n\n";
		}else{
			int m=*it-x;
			it--;
			if(x-*it<m){
				m=x-*it;
			}
			cout<<"Missed it by that much ("<<m<<")!\n\n";
		}
	}
}