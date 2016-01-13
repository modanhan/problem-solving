#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	valarray<int> va(0, 128), t, vb(0, 128), vc(0, 128), zero(0, 128);
	for (char x : a) {
		va[x]++;
	}
	for (char x : b) {
		vb[x]++;
	}
	for (char x : c) {
		vc[x]++;
	}
	t = va;
	int x = 0, best = 0, ugh=0, ughd=0;
	 do{
		int d = 100000000;
		for (int i = 0; i < 128; i++) {
			if (vc[i] != 0){
				d = min(d, va[i] / vc[i]);}
		}

		if (x + d > best) {
			best = x + d;
			ugh = x;
			ughd = d;
		}

		x++;
		va -= vb;
	}while (va.min() >= 0);
//cout<<ugh<<' '<<ughd<<'\n';
	string ans;
	while (ugh--) {
		ans += b;
		t -= vb;
	}
	while (ughd--) {
		ans += c;
		t -= vc;
	}
	for (int i = 0; i < 128; i++) {
	//	cout<<t[i]<<'\n';
		while (t[i]>0) {
			ans += (char) i;
			t[i]--;
		}
	}
	cout<<ans;

}
