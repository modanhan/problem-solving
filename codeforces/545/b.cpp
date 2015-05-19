#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int diff = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			diff++;
		}
	}
	if (diff % 2) {
		cout << "impossible\n";
	} else {
		diff/=2;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				if(diff){
					cout<<a[i];
					diff--;
				}else{
					cout<<b[i];
				}
			}else{
				cout<<'0';
			}
		}
		cout<<"\n";
	}
}
