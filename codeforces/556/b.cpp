#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		for(int c=0;c<n;c++){
			if(v[c]!=c){
				goto bad;
			}
		}
		goto good;
		bad:;
		for(int c=0;c<n;c++){
			if(c%2){
				v[c]++;
				v[c]%=n;
			}else{
				v[c]--;
				if(v[c]<0){
					v[c]+=n;
				}
			}
		}
	}
	cout<<"No\n";
	return 0;
	good:;
	cout<<"Yes\n";
}