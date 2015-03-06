#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<bool> boy(n, 0), girl(m, 0);
	int s; cin >> s;
	for (int i = 0; i < s; i++){
		int t; cin >> t;
		boy[t] = 1;
	}
	cin >> s;
	for (int i = 0; i < s; i++){
		int t; cin >> t;
		girl[t] = 1;
	}

	for (int i = 0; i < 50000; i++){
		boy[i%n] = boy[i%n] | girl[i%m];
		girl[i%m] = girl[i%m] | boy[i%n];
	}
	bool good = 1;
	for (int i = 0; i < n; i++){
		good = good&boy[i];
	}
	for (int i = 0; i < m; i++){
		good = good&girl[i];
	}
	cout << (good ? "Yes\n" : "No\n");
}