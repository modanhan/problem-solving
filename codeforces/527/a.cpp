#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	while (a % b != 0) {
		ans += a / b;
		a %= b;
		if(b>a){
		ll c=a;
		a=b;
		b=c;}
	}
	ans += a / b;
	cout<<ans<<"\n";
}
