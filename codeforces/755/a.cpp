#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll u = 10000000;
bitset<10000001> bs;
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

bool prime(ll n) {
	if (n <= u) {
		return bs[n];
	} else {
		for (int i = 0; i < primes.size(); i++) {
			if (n % primes[i] == 0) {
				return false;
			}
		}
		return true;
	}
}

int main(){
	sieve();
	int x;cin>>x;
	int i=1;
	while(1){
		int p=x*i+1;
		if(!prime(p)){
			cout<<i<<endl;
			return 0;
		}
		i++;
	}
}
