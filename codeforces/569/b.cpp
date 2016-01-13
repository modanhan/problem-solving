#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	vector<int> c(200000,0);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		c[v[i]]++;
	}
	int missing = 1;
	while (c[missing]>0){
		missing++;
	}
	for (int i = 0; i < n; i++){
		if (c[v[i]] > 1||v[i]>n){
			c[v[i]]--;
			v[i] = missing;
			c[missing]++;
			while (c[missing]>0){
				missing++;
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}cout << "\n";
}