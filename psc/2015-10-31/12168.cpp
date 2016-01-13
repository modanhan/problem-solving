#include <bits/stdc++.h>
using namespace std;

class vote {
public:
	char wc, lc;
	int wi, li;
	vote(char w, int wx, char l, int lx) {
		wc = w;
		wi = wx;
		lc = l;
		li = lx;
	}
};

int c, d, v;
int cats = 0;
int adj[600][600];
int matchr[600];
bool seen[600];

bool bpm(int u) {
	for (int vx = 0; vx < v - cats; vx++) {
		if (adj[u][vx] && !seen[vx]) {
			seen[vx] = 1;
			if (matchr[vx] < 0 || bpm(matchr[vx])) {
				matchr[vx] = u;
				return 1;
			}
		}
	}
	return 0;
}

vector<vote> catvotes, dogvotes;

int main() {
	int t;
	cin >> t;

	string s, s2;
	while (t--) {
		cats = 0;
		cin >> c >> d >> v;
		catvotes.clear();
		dogvotes.clear();
		for (int i = 0; i < v; i++) {
			cin >> s >> s2;
			vote asdf(s[0], stoi(s.substr(1)) - 1, s2[0],
					stoi(s2.substr(1)) - 1);
			if (s[0] == 'C') {
				cats++;

				catvotes.push_back(asdf);
			} else {
				dogvotes.push_back(asdf);
			}
		}

		memset(matchr, -1, sizeof matchr);

		for (int i = 0; i < cats; i++) {
			for (int j = 0; j < v - cats; j++) {
				if (catvotes[i].wi == dogvotes[j].li) {
					adj[i][j] = 1;
				} else if (catvotes[i].li == dogvotes[j].wi) {
					adj[i][j] = 1;
				} else {
					adj[i][j] = 0;
				}
			}
		}
		/*		for (int i = 0; i < v; i++) {
		 for (int j = 0; j < v; j++) {
		 cout<<adj[i][j];
		 }cout<<'\n';
		 }*/

		int ans = 0;
		for (int i = 0; i < cats; i++) {
			memset(seen, 0, sizeof seen);
			if (bpm(i))
				ans++;
		}

		cout << (v - ans) << '\n';

	}
}
