#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, bool> ib;
typedef pair<int, int> ii;
int n, k;
vector<ib> v;
int main(){
	scanf("%d %d", &n, &k);
//	cin >> n >> k;
//	v.assign(2*n, ib(0, false));
	for (int i = 0; i < n; i++){
		int x, y;// cin >> x >> y;
		scanf("%d %d", &x, &y);
		v.push_back(ib(x, true));
		v.push_back(ib(y + 1, false));
//		v[2 * i].first = x;
//		v[2 * i].second = 1;
//		v[2 * i + 1].first = y;
	}
	sort(v.begin(), v.end());
	vector<ii> ans;
	
	int c=0, b=-1;
	for (int i = 0; i < 2 * n; i++){
		if (v[i].second == true){
			c++;
		}
		else c--;
		if (c >= k&&b==-1){
			b = i;
		}
		if (c < k&&b != -1){
			ans.push_back(ii(v[b].first, v[i].first-1));
			b = -1;
		}
	//	cout << v[i].first<<" " << v[i].second<<" " << c << endl;
	}
	
	cout << ans.size() << endl;
	for (ii x : ans){
		printf("%d %d\n", x.first, x.second);
//		cout << x.first << ' ' << x.second << endl;
	}
}