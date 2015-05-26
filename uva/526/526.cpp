#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	while (getline(cin, a)) {
		getline(cin, b);
		if (a.size() == 0) {
			cout << b.size() << "\n";
			for(int i=0;i<b.size();i++){
				cout<<(i+1)<<" Insert "<<(i+1)<<","<<b[i]<<"\n";
			}
			cout << "\n";
			continue;
		}
		if (b.size() == 0) {
			cout << a.size() << "\n";
			for (int i = 1; i <= a.size(); i++) {
				cout << i << " Delete 1\n";
			}
			cout << "\n";
			continue;
		}
		vector < vector<int> > v(a.size() + 1, vector<int>(b.size() + 1, -1));
		for (int i = 0; i <= a.size(); i++)
			v[i][0] = i;
		for (int i = 0; i <= b.size(); i++)
			v[0][i] = i;
		for (int i = 1; i <= a.size(); i++) {
			for (int j = 1; j <= b.size(); j++) {
				int m;
				if (a[i - 1] == b[j - 1]) {
					m = 0;
				} else {
					m = 1;
				}
				int di;
				if (v[i - 1][j] < v[i][j - 1]) {
					di = v[i - 1][j] + 1;
				} else {
					di = v[i][j - 1] + 1;
				}
				if (v[i - 1][j - 1] + m < di) {
					v[i][j] = v[i - 1][j - 1] + m;
				} else {
					v[i][j] = di;
				}
			}
		}
		/*	for (int i = 0; i <= a.size(); i++) {
		 for (int j = 0; j <= b.size(); j++) {
		 cout << v[i][j] << "\t";
		 }
		 cout << "\n";
		 }*/
		cout << v.back().back() << "\n";
		int i = a.size(), j = b.size(), c =1;
		while (c <= v.back().back()) {
			int m;
			if (a[i - 1] == b[j - 1]) {
				m = 0;
			} else {
				m = 1;
			}
			if(i!=0&&j!=0&&v[i][j]==v[i-1][j-1]+m){
				if(m){
					cout<<c<<" Replace "<<i<<","<<b[j-1]<<"\n";
					c++;
				}
				i--;j--;
			}else if(j!=0&&v[i][j]==v[i][j-1]+1){
				cout<<c<<" Insert "<<(i+1)<<","<<b[j-1]<<"\n";
				c++;
				j--;
			}else{
				cout<<c<<" Delete "<<i<<"\n";	
				c++;i--;
			}
		}
	}
}
