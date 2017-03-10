#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll u = 1000000;
bitset<1000001> bs;
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

ll n, ans, tans;
double d;
typedef pair<ll,ll> ii;
vector<ii> v;

int main(){
    sieve();
    int t;cin>>t;
    while(t--){
        tans=ans=0;
        cin>>n>>d;
        v.assign(n+1,ii(0,0));
        for(int i=1;i<=n;i++){
            cin>>v[i].first>>v[i].second;
        }
        int ci=1;
        while(1){
            if(ci>n)break;
            d-=sqrt((v[ci].first-v[ci-1].first)*(v[ci].first-v[ci-1].first)+(v[ci].second-v[ci-1].second)*(v[ci].second-v[ci-1].second));
            if(d<0)break;
            tans++;
            if(prime(tans))ans=tans;
            ci++;
        }
        cout<<ans<<endl;
    }
}
