#include <iostream>
#include <string>
using namespace std;

int main(){
	int b1, b2, b3, g1, g2, g3, c1, c2, c3;
	while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){
		string ans = "BCG";
		int min = g1 + c1 + b2 + g2 + b3 + c3;
		int t = g1 + c1 + b2 + c2 + b3 + g3;
		if (t<min){
			min = t;
			ans = "BGC";
		}
		t = g1 + b1 + c2 + g2 + b3 + c3;
		if (t<min){
			min = t;
			ans = "CBG";
		}
		t = g1 + b1 + b2 + c2 + g3 + c3;
		if (t<min){
			min = t;
			ans = "CGB";
		}
		t = b1 + c1 + c2 + g2 + b3 + g3;
		if (t<min){
			min = t;
			ans = "GBC";
		}
		t = b1 + c1 + b2 + g2 + g3 + c3;
		if (t<min){
			min = t;
			ans = "GCB";
		}
		cout << ans << " " << min << "\n";
	}
	return 0;
}