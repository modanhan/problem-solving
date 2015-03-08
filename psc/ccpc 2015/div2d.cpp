#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
int main(){
	vector<ll> v;
	for (ll i = 1; i < (1 << 19); i++){
		ll t = 1;
		ll c=0;
		for (ll k = 1; k < (1<<19); k<<=1){
			if (k&i){
				c += t;
			}
			t *= 10;
		}
		v.push_back(c);
	}

	int tc;
	cin >> tc;
	while (tc--){
		int x;
		cin >> x;
		for (ll i : v){
			if (i%x == 0){
				cout << i << "\n";
				break;
			}
		}
	}
}