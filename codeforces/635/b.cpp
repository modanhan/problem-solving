#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
int n;

bool sc() {
	int v2i = 0;
	for (; v2i < n; v2i++) {
		if (v2[v2i] == v1[0])
			break;
	}
	for(int i=0;i<n;i++){
		if(v1[i]!=v2[(v2i+i)%n])return 0;
	}
	return 1;
}

int main() {
	cin >> n;
	n--;
	v1.assign(n, 0);
	v2.assign(n, 0);
	for (int i = 0; i < n;) {
		int x;
		cin >> x;
		if (x) {
			v1[i] = x;
			i++;
		}
	}
	for (int i = 0; i < n;) {
		int x;
		cin >> x;
		if (x) {
			v2[i] = x;
			i++;
		}
	}

	if(sc()){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
