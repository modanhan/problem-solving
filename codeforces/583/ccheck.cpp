#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<ll> a,b;
	for(int i=0;i<50;i++){
		int x;cin>>x;a.push_back(x);
	}
	for(int i=0;i<50;i++){
			int x;cin>>x;b.push_back(x);
		}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(ll i:a){
		cout<<i<<' ';
	}cout<<'\n';
	for(ll i:b){
			cout<<i<<' ';
		}cout<<'\n';
	cout<<(a==b);
}