#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	if (a < 0){
		a *= -1;
	}
	if (b < 0){
		b *= -1;
	}
	if (a + b <= c){
		if ((a + b) % 2 == c % 2){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else{
		cout << "No\n";
	}
}