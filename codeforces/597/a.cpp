#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll k, a, b; cin >> k >> a >> b;
	if (k == 0){
		cout << 0;
		return 0;
	}
	if (k == 1){
		cout << (b - a + 1);
		return 0;
	}
//	ll ans =( b - a + 1) / k;
	ll first = (a / k)*k;
	if (first < a)first += k;
	ll last = (b / k)*k;
	if (last > b)last -= k;
//	cout << first << "\t" << last << endl;
	
	cout << (last-first)/k+1;
}