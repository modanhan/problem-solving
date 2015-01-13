#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> m(1000010, -1);
	vector<int> im(1000010, -1);
	vector<bool> bs(1000010, false);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bs[a]=true;
		bs[b]=true;
		m[a] = b;
		im[b] = a;
	}
	if (n % 2) {
		
		queue<int> f, s;
		int c = m[0];
		while (c != 0) {
			f.push(c);
			bs[c] = false;
			c = m[c];
		}

		stack<int> q;
		int n = 0;
		for (int i = 1; i < 1000005; i++) {
			if (bs[i]) {
				n = i;
				break;
			}
		}

		s.push(n);
		c = m[n];
		while (c != -1) {
			s.push(c);
			c = m[c];
		}
		c = n;
		c = im[c];
		while (c != -1) {
			q.push(c);
			c = im[c];
		}

		
		while (!f.empty()) {
			if (!q.empty()) {
				cout << q.top() << " " << f.front() << " ";
				q.pop();
			} else {
				cout << s.front() << " " << f.front() << " ";
				s.pop();
			}
			f.pop();
		}
		if (!q.empty()) {
			cout << q.top() << "\n";
			q.pop();
		} else {
			cout << s.front() << "\n";
			s.pop();
		}
	} else {
		queue<int> f;
		stack<int> s;
		int c = m[0];
		while (c != -1) {
			f.push(c);
			c = m[c];
		}
		c = im[0];
		while (c != -1) {
			s.push(c);
			c = im[c];
		}
		while (!f.empty()) {
			cout << s.top() << " " << f.front() << " ";
			f.pop();
			s.pop();
		}
		cout << "\n";
	}
}
