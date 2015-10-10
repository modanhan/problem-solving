#include <bits/stdc++.h>
using namespace std;

double h, v, l, s, ans,t;

double f(double theta) {
	double vx = cos(theta) * v, vy = sin(theta) * v;
//	t = (-vy + sqrt(vy * vy + 20 * h)) / (-10);
	t=(-vy - sqrt(vy * vy + 20 * h)) / (-10);
	double run = l + t * s;
	double dist = vx * t;
	return min(run,dist);
}

double ternarysearch(double l, double r, double e) {
	int t=10000;
	while (t--) {
	//	if (abs(r - l) < e)
	//		return (l + r) / 2;
		double lt = (2 * l + r) / 3, rt = (l + 2 * r) / 3;
		if (f(lt) < f(rt))
			l = lt;
		else
			r = rt;
	}
	return (l+r)/2;
}

int main() {
	while (cin >> h >> v >> l >> s) {
		double ans = f(ternarysearch(0, M_PI/2, .000000001));
		if (ans >= l)
			printf("%.3f\n", min(ans,t*s+l));
		else printf("BAD THROW\n");
	}
}
