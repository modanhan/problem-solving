#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

vector<int> a, b,c,d;
int main(){
	cin >> n;
	a.assign(n, 0);
	b.assign(1000001, 0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		int x; cin >> x;
		b[a[i]] = x;
	}
	sort(a.begin(), a.end());
	c.assign(n+1, 0);
	//c[i]=num of beacon i can destroy
	c[0] = 0;
	for (int i = 1; i < n; i++){
		auto it = lower_bound(a.begin(), a.begin() + i, a[i] - b[a[i]]);
		c[i] = distance(it, a.begin() + i);
	//	cout << c[i];
	}
	//d[i]=min number destroyed if i is active
	d.assign(n, 0);
	d[0] = 0;
	for (int i = 1; i < n; i++){
		d[i] = c[i] + d[(i - c[i] - 1)<0 ? 0 : (i - c[i] - 1)];
	//	cout << d[i];
	}
	int ans = n;
	for (int i = 0; i < n; i++){
		ans = min(ans, d[i] + n - i - 1);
	}
	cout << ans;
	
}