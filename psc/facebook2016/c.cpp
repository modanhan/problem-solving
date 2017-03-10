#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
int n;
vector<ii> v;
int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		v.assign(n, ii(0, 0));
		for(int i=0;i<n;i++){
			cin>>v[i].first>>v[i].second;
		}
		sort(v.begin(),v.end());
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[j].second>v[i].second)break;
				if(v[j].second==v[i].second){
					ll x=(v[j].first-v[i].first)%mod;
					ans+=(x*x)%mod;
					ans%=mod;
				}
			}
		}
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
}
