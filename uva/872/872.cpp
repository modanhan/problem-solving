#include <bits/stdc++.h>
using namespace std;

map<char, vector<char> > g;
int p(vector<int> indegree, string s) {
	vector<char> zeros;
	for (auto a : g) {
		if (indegree[a.first] == 0) {
			zeros.push_back(a.first);
		}
	}
	if (zeros.empty()) {
		for(auto a:g){
			if(indegree[a.first]>0){
				return 0;
			}
		}
		cout << s << endl;
		return 1;
	}
	sort(zeros.begin(), zeros.end());
	int dag=1;
	for (char c : zeros) {
		vector<int> indegree1 = indegree;
		indegree1[c] = -1;
		for (char x : g[c]) {
			indegree1[x]--;
		}
		string t = "";
		if (s == "") {
			t += c;
		} else {
			t = s + ' ' + c;
		}
		dag=dag&&p(indegree1, t);
	}
	return dag;
}

int main() {
	string line;
	getline(cin, line);
	int T = stoi(line);
	int t=T;
	while (t--) {
		if(t<T-1){
			cout << "\n";
		}
		stringstream ss1, ss2;
		getline(cin, line);
		getline(cin, line);
		ss1 << line;
		getline(cin, line);
		ss2 << line;
		g.clear();
		char c;
		while (ss1 >> c) {
			g[c] = vector<char>();
		}
		string buffer;
		while (ss2 >> buffer) {
			g[buffer[0]].push_back(buffer[2]);
		}
		/*	for(auto a:g){
		 cout<<a.first<<": ";
		 for(auto x:a.second){
		 cout<<x<<" ";
		 }cout<<"\n";
		 }*/
		vector<int> indegree(128, 0);
		for (auto a : g) {
			for (auto x : a.second) {
				indegree[x]++;
			}
		}
		for (auto a : g) {
			if (indegree[a.first] == 0) {
				goto ok;
			}
		}
		cout << "NO\n";
		continue;
		ok: if(p(indegree, "")){
		}else{
			cout << "NO\n";
		}
	}
}
