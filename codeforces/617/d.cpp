#include <bits/stdc++.h>
using namespace std;

bool l(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (x1 == x2 && (y3<=min(y1,y2)||y3>=max(y1,y2)))
		return 1;
	if (y1 == y2 && (x3<=min(x1,x2)||x3>=max(x1,x2)))
		return 1;
	return 0;
}
int main() {
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 == x2 && x2 == x3) {
		cout << 1;
		return 0;
	}
	if (y1 == y2 && y2 == y3) {
		cout << 1;
		return 0;
	}
	if(l(x1,y1,x2,y2,x3,y3)||
			l(x1,y1,x3,y3,x2,y2)||
	l(x2,y2,x1,y1,x3,y3)||
	l(x2,y2,x3,y3,x1,y1)||
	l(x3,y3,x2,y2,x1,y1)||
	l(x3,y3,x1,y1,x2,y2)) {
		cout<<2;return 0;
	}
	cout << 3;
}