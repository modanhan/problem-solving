#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long n, k;
	while (cin >> n >> k) {
		long double ans = 0;
		for (unsigned long long i = 0; i < k; i+=1) {
			ans += log10((double)(n - i));
			ans -= log10((double)(i + 1));
		//	cout<<ans<<endl;
		}
	//	if(ans<0)ans=0;
		cout << (floor(ans)) + 1 << endl;
	}
}
