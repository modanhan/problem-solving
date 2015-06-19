#include <bits/stdc++.h>
using namespace std;
int main() {
	int x;
	vector<int> v, list, listi, p;
	while (cin >> x) {
		v.push_back(x);
	}
	p.assign(v.size(), -1);
	list.push_back(v.front());
	listi.push_back(0);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > list.back()) {
			list.push_back(v[i]);
			p[i] = listi.back();
			listi.push_back(i);
		} else {
			auto it = lower_bound(list.begin(), list.end(), v[i]);
			if (v[i] != *it) {
				*it = v[i];
				if (it == list.begin()) {
					p[i] = -1;
					listi[0]=i;
				} else {
					int dist = it - list.begin();
					listi[dist] = i;
					p[i] = listi[dist - 1];
				}
			}else{
				int dist = it - list.begin();
				p[i]=p[listi[dist]];
			}
		}
	}
/*	for(int i:v){
		cout<<i<<"\t";
	}cout<<"\n";
	for(int i:p){
		cout<<i<<"\t";
	}*/
	int last=listi.back();
	stack<int> s;
	cout<<list.size()<<"\n-\n";
	while(last!=-1){
		s.push(v[last]);
		last=p[last];
	}
	while(!s.empty()){
		cout<<s.top()<<"\n";
		s.pop();
	}
}
