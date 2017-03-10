#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll> > c(70, vector < ll > (70, 0));


int main() {

	for (int i = 0; i < 70; i++) {
		c[i][0] = 1;	//i choose 0, 1 way
	}
	for (int i = 1; i < 70; i++) {
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	
	int t;cin>>t;
	for(int asdf=1;asdf<=t;asdf++){
		int n,k;
		cin>>n>>k;
		cout<<"Case "<<asdf<<": "<<c[n][k-1]<<endl;
	}
}
