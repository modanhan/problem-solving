#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
int main() {
	ll n;
	cin >> n;
	vl f(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> f[i];
	}
	ll m;
	cin >> m;
	vl s(m, 0);
	for (ll i = 0; i < m; i++) {
		cin >> s[i];
	}
	sort(f.begin(), f.end());
	sort(s.begin(), s.end());
	ll maxx = -9233372123456789, mf = 0, ms = 0;
	for (auto it = f.begin(); it != f.end(); it++) {
		//upper bound is <=
		ll fi = upper_bound(f.begin(), f.end(), *it) - f.begin();
		ll si = upper_bound(s.begin(), s.end(), *it) - s.begin();
		ll fp = fi * 2 + (n - fi) * 3;
		ll sp = si * 2 + (m - si) * 3;
		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}

		fi = upper_bound(f.begin(), f.end(), (*it) - 1) - f.begin();
		si = upper_bound(s.begin(), s.end(), (*it) - 1) - s.begin();
		fp = fi * 2 + (n - fi) * 3;
		sp = si * 2 + (m - si) * 3;

		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}

		fi = upper_bound(f.begin(), f.end(), (*it) + 1) - f.begin();
		si = upper_bound(s.begin(), s.end(), (*it) + 1) - s.begin();
		fp = fi * 2 + (n - fi) * 3;
		sp = si * 2 + (m - si) * 3;
		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		//upper bound is <=
		ll fi = upper_bound(f.begin(), f.end(), *it) - f.begin();
		ll si = upper_bound(s.begin(), s.end(), *it) - s.begin();
		ll fp = fi * 2 + (n - fi) * 3;
		ll sp = si * 2 + (m - si) * 3;
		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}

		fi = upper_bound(f.begin(), f.end(), (*it) - 1) - f.begin();
		si = upper_bound(s.begin(), s.end(), (*it) - 1) - s.begin();
		fp = fi * 2 + (n - fi) * 3;
		sp = si * 2 + (m - si) * 3;
		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}
		fi = upper_bound(f.begin(), f.end(), (*it) + 1) - f.begin();
		si = upper_bound(s.begin(), s.end(), (*it) + 1) - s.begin();
		fp = fi * 2 + (n - fi) * 3;
		sp = si * 2 + (m - si) * 3;
		if (fp - sp > maxx) {
			maxx = fp - sp;
			mf = fp;
			ms = sp;
		} else if (fp - sp == maxx) {
			mf = max(fp, mf);
			ms = max(sp, ms);
		}
	}
	cout << mf << ":" << ms << "\n";
}
