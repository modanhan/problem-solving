#include <bits/stdc++.h>
using namespace std;
# define PI           3.14159265358979323846
typedef pair<double, double> dd;
int n;
vector<dd> v;
double maxd = 0, mind = 10000000000;
double cx, cy, px, py, cd, x, y;
int main() {
	cin >> n >> x >> y;
	v.assign(n, dd(0, 0));

	cin >> v[0].first >> v[0].second;
	cx = v[0].first;
	cy = v[0].second;
	cd = hypot(cx - x, cy - y);
	if (cd > maxd)
		maxd = cd;
	if (cd < mind)
		mind = cd;

	for (int i = 1; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		cx = v[i].first;
		cy = v[i].second;
		px = v[i - 1].first;
		py = v[i - 1].second;

		cd = hypot(cx - x, cy - y);
		if (cd > maxd)
			maxd = cd;
		if (cd < mind)
			mind = cd;

		// cloest point on a line
		double u = (x - px) * (cx - px) + (y - py) * (cy - py);
		u /= (cx - px) * (cx - px) + (cy - py) * (cy - py);

		double ix = px + u * (cx - px), iy = py + u * (cy - py);
		if (abs(
				hypot(cx - px, cy - py)
						- (hypot(ix - px, iy - py) + hypot(ix - cx, iy - cy)))
				< .00001f) {
			mind = min(mind, hypot(ix - x, iy - y));
		}
	}
	cx = v[0].first;
	cy = v[0].second;
	px = v.back().first;
	py = v.back().second;
	{
		double u = (x - px) * (cx - px) + (y - py) * (cy - py);
		u /= (cx - px) * (cx - px) + (cy - py) * (cy - py);

		double ix = px + u * (cx - px), iy = py + u * (cy - py);
		if (abs(
				hypot(cx - px, cy - py)
						- (hypot(ix - px, iy - py) + hypot(ix - cx, iy - cy)))
				< .00001f) {
			mind = min(mind, hypot(ix - x, iy - y));
		}
	}
//	cout << maxd << ' ' << mind << '\n';
	double ans = PI * maxd * maxd - PI * mind * mind;
	if (ans < 0)
		ans *= -1;
	printf(("%.16f"), ans);

}
