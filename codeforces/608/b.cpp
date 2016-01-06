#include <string>
#include <iostream>
#include <vector>
using namespace std;
string a, b;
vector<long long> y;
int main(){
	cin >> a >> b;
	y.assign(b.size(), 0);
	if (b[0] == '1') y[0] = 1;
	for (int i = 1; i < b.size(); i++){
		if (b[i] == '0'){
			y[i] = y[i - 1];
		}
		else{
			y[i] = y[i - 1]+1;
		}
	}
//	for (int i = 0; i < x.size(); i++){
//		cout << x[i] << y[i] << endl;
//	}
	long long ans = 0;
	int d = b.size() - a.size();
	if (a[0] == '0'){
		ans = y[ d];
	}
	else{
		ans = d + 1 - y[ d];
	}
	for (int i = 1; i < a.size(); i++){
		if (a[i] == '0'){
			ans += y[i+d] -  y[i - 1];
		}
		else{
			ans += d+1-(y[i + d] - y[i - 1]);
		}
	}
	cout << ans;
}