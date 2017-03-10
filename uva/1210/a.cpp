#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll u = 20000;
bitset<20001> bs;
vector<ll> primes,ps;
void sieve() {
	u++;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < u; i++) {
		if(bs[i])
		{
			for (ll j = i * i; j < u; j += i) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

int main() {
	sieve();
	ps.assign(primes.size()+1,0);
	for(int i=0;i<primes.size();i++){
		ps[i+1]=primes[i]+ps[i];
	}
	int n;
	while (1) {
		cin >> n;
		if (n) {
			int ans=0;
			int x=distance(primes.begin(),lower_bound(primes.begin(),primes.end(),n));
			x++;
			for(int i=1;i<=x;i++){
				for(int j=i;j<=x;j++){
					int sum=ps[j]-ps[i-1];
					if(sum==n){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		} else
			break;
	}
}
