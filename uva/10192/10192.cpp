#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	getline(cin,a);
	int c = 1;
	while (a[0] != '#') {
		getline(cin,b);

		vector < vector<int> > v(a.size() + 1, vector<int>(b.size() + 1, 0));
		for (int i = 1; i <= a.size(); i++) {
			for (int j = 1; j <= b.size(); j++) {
				int m;
				if (a[i-1] == b[j-1]) {
					m = 1;
				} else {
					m = -100000000;
				}
				v[i][j] = max(v[i - 1][j - 1] + m,
						max(v[i - 1][j], v[i][j - 1]));
			}
		}
		cout << "Case #" << c << ": you can visit at most " << v.back().back()
				<< " cities.\n";
		c++;
		getline(cin,a);
	}
}
