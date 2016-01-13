#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<int> sa, lcp;

void computelcp() {
	lcp[0] = 0;
	for (int i = 1; i < n; i++) {
		int l = 0;
		while (s[sa[i] + l] == s[sa[i - 1] + l])
			l++;
		lcp[i] = l;
	}
}

bool cmp(int a, int b) {
	return s.substr(a) < s.substr(b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		s += '$';
		n = s.size();
		sa.assign(n, 0);
		lcp.assign(n, 0);
		for (int i = 0; i < n; i++)
			sa[i] = i;
		sort(sa.begin(), sa.end(), cmp);
		computelcp();
	//	for (int i = 0; i < n; i++) {
	//		cout << s.substr(sa[i]) << '\t' << lcp[i] << '\n';
	//	}
		int maxi = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			if (lcp[i] >= lcp[maxi])
				maxi = i;
		}
		set < string > anss;

		int lcpmax = lcp[maxi];
		if (lcpmax) {
			for (int i = 1; i < n; i++) {
				if (lcp[i] == lcpmax) {
					//found it
					ans++;
					continue;
				}
				if (ans) {
					cout << s.substr(sa[i - 1], lcpmax) << ' ' << ans + 1
							<< '\n';
					goto done;
				}
			}
			if (ans) {
				cout << s.substr(sa.back(), lcpmax) << ' ' << ans + 1 << '\n';
				goto done;
			}
		}
		cout << "No repetitions found!\n";
		done:;
	}
}
