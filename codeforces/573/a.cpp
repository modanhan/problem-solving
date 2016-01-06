#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
	if (b == 0)return a;
	else return gcd(b, a%b);
}

bool good(int a){
	if (a == 1){
		return 1;
	}
	if (a % 2 == 0){
		return good(a / 2);
	}
	if (a % 3 == 0){
		return good(a / 3);
	}
	return 0;
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int g = gcd(v[0], v[1]);
	for (int i = 2; i < n; i++){
		g = gcd(g, v[i]);
	}
	for (int i = 0; i < n; i++){
		v[i] /= g;
		if (!good(v[i])){
			goto bad;
		}
	}
	cout << "Yes\n";
	return 0;
bad:
	cout << "No\n";
}