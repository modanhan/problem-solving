#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(vector<int> s, vector<int> k) {
	vector<int> t(k.size() + 1, -1);
	vector<int> ans;
	if (k.size() == 0) {
		ans.push_back(0);
		return ans;
	}
	for (int i = 1; i <= k.size(); i++) {
		int pos = t[i - 1];
		while (pos != -1 && k[pos] != k[i - 1]) {
			pos = t[pos];
		}
		t[i] = pos + 1;
	}
	int sp = 0, kp = 0;
	while (sp < s.size()) {
		while (kp != -1 && (kp == k.size() || k[kp] != s[sp])) {
			kp = t[kp];
		}
		kp++;
		sp++;
		if (kp == k.size()) {
			ans.push_back(sp - k.size());
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> c1(n, 0), c2(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> c1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c2[i];
	}
	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());
	vector<int> d1(n, 0), d2(n * 2, 0);
	for (int i = 1; i < n; i++) {
		d1[i - 1] = c1[i] - c1[i - 1];
		d2[i - 1] = c2[i] - c2[i - 1];
		d2[i - 1 + n] = c2[i] - c2[i - 1];
	}
	d1[n-1]=360000-c1[n-1]+c1[0];
	d2[n-1]=360000-c2[n-1]+c2[0];
	d2[2*n-1]=360000-c2[n-1]+c2[0];
	vector<int> v=kmp(d2,d1);
	
/*	for(int i:d1){
		cout<<i<<" ";
	}cout<<"\n";
	for(int i:d2){
			cout<<i<<" ";
		}cout<<"\n";
	*/
	if(v.empty()){
		cout<<"impossible\n";
	}else{
		cout<<"possible\n";
	}
}
