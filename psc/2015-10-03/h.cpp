#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		int k;
		for (k = 0; k * k < s.size(); k++)
			;
		vector < vector<char> > v(k, vector<char>(k));
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i * k + j < s.size())
					v[i][j] = s[i * k + j];
				else
					v[i][j] = '*';
			}
		}
		for(int j=0;j<k;j++){
		for(int i=k-1;i>=0;i--){
			if(v[i][j]!='*')cout<<v[i][j];
		}}cout<<'\n';
	}
}
