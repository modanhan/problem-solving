#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	vector<string> v(n, "");
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int ans = 0;
	vector<bool> check(n, 1);
	for (int i = 0; i < m; i++){
		bool sorted = 1;
		bool strict = 1;
		for (int j = 1; j < n; j++){
			if (!check[j]){
				continue;
			}
			if (v[j][i] < v[j-1][i]){
				sorted = 0;
				break;
			}
			else if (v[j][i] == v[j - 1][i]){
				strict = 0;
			}
		}
		if (sorted&&strict){
			break;
		}
		if (!sorted){
			ans++;
		}
		else{
			for (int j = 1; j < n; j++){
				if (!check[j]){
					continue;
				}
				else if (v[j][i] != v[j - 1][i]){
					check[j] = 0;
				}
			}
		}
	}
	cout << ans;
}