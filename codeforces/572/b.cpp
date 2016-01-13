#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
	int n, s; cin >> n >> s;
	vector<int> v(200000),seen(200000,0);
	while (n--){
		char c; int p, q;
		cin >> c >> p >> q;
		seen[p] = 1;
		if (c == 'B'){
			v[p] += q;
		}
		else{
			v[p] -= q;
		}
	}
	set<pair<int, int> > t;
	for (int i = 0; i < 100001; i++){
		if (seen[i]){
			t.insert(pair<int, int>(v[i],i));
		}
	}
	int index = 0;
	auto it = t.begin();
	while (1){
		if (index == s||it==t.end()||it->first>0){
			break;
		}
		cout << "S " << it->second << " " << (-(it->first)) << "\n";
		it++;
		index++;
	}
	index = 0;
	it = t.end();
	it--;
	while (1){
		if (index == s || it->first < 0){
			break;
		}
		cout << "B " << it->second << ' ' << it->first << "\n";
		if (it == t.begin()){
			break;
		}
		it--;
		index++;
	}
}