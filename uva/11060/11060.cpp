#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> > m;
map<string, int> indeg, order;

struct ugh {
	bool operator()(string a, string b) {
		return order[a] >= order[b];
	}
};

int main() {
	int N, M,x=0;
	while (cin >> N) {
		x++;
		m.clear();
		indeg.clear();
		order.clear();
		for (int i = 0; i < N; i++) {
			vector < string > v;
			string s;
			cin >> s;
			m[s] = v;
			indeg[s] = 0;
			order[s] = i;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			string s, t;
			cin >> s >> t;
			m[s].push_back(t);
		}
		for (pair<string, vector<string> > p : m) {
			for (string s : p.second) {
				indeg[s]++;
			}
		}
		priority_queue<string, vector<string>, ugh> zero;
		for (pair<string, int> p : indeg) {
			if (p.second == 0) {
				zero.push(p.first);

			}
		}
		vector < string > ans;
		while (!zero.empty()) {
			string s=zero.top();
			ans.push_back(s);
			zero.pop();
			for (string nb : m[s]) {
				indeg[nb]--;
				if (indeg[nb] == 0) {
					zero.push(nb);
				}
			}
		}
		cout<<"Case #"<<x<<": Dilbert should drink beverages in this order:";
		for(string s:ans){
			cout<<" "<<s;
		}cout<<".\n\n";
	}
	return 0;
}
