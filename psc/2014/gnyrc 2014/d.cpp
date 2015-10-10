#include <bits/stdc++.h>
using namespace std;

typedef long int ll;
ll u = 10002;
bitset<10003> bs;

void sieve() {
	u++;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < u; i++) {
		if (bs[i]) {
			for (ll j = i * i; j < u; j += i) {
				bs[j] = 0;
			}
		}
	}
}

vector<bool> found;

bool happy(int i){
//	cout<<i<<"\n";
	int sum=0;
	int pow=1;
	for(int x=1;x<5;x++){
		sum+=((i/pow)%(10))*((i/pow)%(10));
		pow*=10;
	}
	if(sum==1){
			return true;
		}
	if(found[sum]){
		return false;
	}
	found[sum]=1;
	if(sum==2||sum==3||sum==5){
		return false;
	}
	return happy(sum);
}

int main() {
	sieve();
	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		found.assign(500,0);
		int blah;cin>>blah;
		int i;cin>>i;
		if(bs[i]){
			if(happy(i)){
				cout<<t<<" "<<i<<" YES\n";
			}else{
				cout<<t<<" "<<i<<" NO\n";
			}
		}else{
			cout<<t<<" "<<i<<" NO\n";
		}
	}
}