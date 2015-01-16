#include <bits/stdc++.h>
using namespace std;

int main() {
	int f, r;
	cin >> f;
	while (f != 0) {
		cin >> r;
		vector<int> fv(f, 0), rv(r, 0);
		for (int i = 0; i < f; i++) {
			cin >> fv[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> rv[i];
		}
		vector<double> d;
		for (int i : fv) {
			for (int j : rv) {
				d.push_back((double) i / (double) j);
			}
		}
		sort(d.begin(), d.end());
		double ans = 0;
		for (int i = 1; i < d.size(); i++) {
			ans = max(ans, d[i] / d[i - 1]);
		}
		printf("%.2f\n",ans);
		cin >> f;
	}
}
