#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		int h, m, s, cm, cs;
		scanf("%d:%d:%d %d:%d", &h, &m, &s, &cm, &cs);
		bool good = 0;
		do {
			if (h == cm && m == cs) {
				good = 1;
				//	cerr<<h<<' '<<m<<' '<<s<<'\n';
				break;
			}
			cs--;
			if (cs == -1) {
				cs = 59;
				cm--;
			}
			s++;
			if (s == 60) {
				s = 0;
				m++;
				if (m == 60) {
					m = 0;
					h++;
					if (h == 24) {
						h = 0;
					}
				}
			}
		} while (cm >= 0);
		if (h == cm && m == cs) {
			good = 1;
		}
		cout << (good ? "Yes\n" : "No\n");
	}
}
