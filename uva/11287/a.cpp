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

ll a, p;

ll exp(ll b, ll e) {
	if (e == 0)
		return 1;
	if (e == 1)
		return b;
	if (e % 2)
		return (b * exp((b * b) % p, e >> 1)) % p;
	else
		return (exp((b * b) % p, e >> 1)) % p;
}

int main() {
	sieve();
	while (1) {
		cin >> p >> a;
		if (p == 0)
			break;
		if (exp(a, p) % p == a&&(!prime(p))) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}
