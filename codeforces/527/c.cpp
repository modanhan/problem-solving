#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll w, h, n;
set<ll> sw, sh,gw,gh;
vector<ll> vw(300000,0), vh(300000,0);

int main(){
	cin >> w >> h >> n;
	sw.insert(w);
	sh.insert(h);
	vw[w] = 1;
	vh[h] = 1;
	gw.insert(0);
	gw.insert(w);
	gh.insert(h);
	gh.insert(0);
	while (n--){
		char c; ll x;
		cin >> c >> x;
		if (c == 'H'){
			
			auto l = gh.lower_bound(x);
			auto u = l;
			l--;
			int length = *u - *l;

			vh[length]--;
			if (vh[length] == 0){
				sh.erase(length);
			}

			if (vh[x - *l] == 0){
				sh.insert(x - *l);
			}
			vh[x - *l]++;

			if (vh[*u - x] == 0){
				sh.insert(*u - x);
			}
			vh[*u - x]++;

			gh.insert(x);
		}
		else{
			
			auto l = gw.lower_bound(x);
			auto u = l;
			l--;
			int length = *u - *l;

			vw[length]--;
			if (vw[length] == 0){
				sw.erase(length);
			}

			if (vw[*u - x] == 0){
				sw.insert(*u - x);
			}
			vw[*u - x]++;

			if (vw[x - *l] == 0){
				sw.insert(x - *l);
			}
			vw[x - *l]++;

			gw.insert(x);
		}
		cout << (*sw.rbegin())*(*sh.rbegin())<<endl;
	}
}