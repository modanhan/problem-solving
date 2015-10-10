#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int tc;
	cin >> tc;
	for (int tx = 0; tx < tc; tx++) {
		int h, w;
		cin >> h >> w;
		vector < string > m(h, "");
		for (int i = 0; i < h; i++) {
			cin >> m[i];
		}
		int sx, sy;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] == 'S') {
					sx = j;
					sy = i;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] == 'B') {
					ans += abs(i - sy);
					ans += abs(j - sx);
				}
			}
		}

		cout << (ans * 2) << " seconds to blocks get!\n";
	}
}
