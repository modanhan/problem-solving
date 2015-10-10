#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vowel(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'){
		return true;
	}else return false;
}

int main(){
	int n;cin>>n;
	for(int t=1;t<=n;t++){
		string s;cin>>s;
		bool v,really=1;
		for(int i=0;i<s.size();i++){
			if(s[i]!='?'){
				v=vowel(s[i]);
				if(i%2){
					v=!v;
				}
				really=0;
			}
		}
		if(really){
			ll x=1,y=1;
			for(int i=0;i<s.size();i++){
				x*=(i%2)?6:20;
				y*=(i%2)?20:6;
			}cout<<"String #"<<t<<": "<<x+y<<"\n";
			continue;
		}
		bool bad=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!='?'){
			if((i%2==1)&&vowel(s[i])==v){
				bad=1;break;
			}else if((i%2==0)&&vowel(s[i])!=v){
				 bad=1;break;
			}
			}
		}if(bad){
			cout<<"String #"<<t<<": 0\n";continue;
		}
		ll ans=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='?'){
				if(i%2){
					ans*=v?20:6;
				}else{
					ans*=v?6:20;
				}
			}
		}
		cout<<"String #"<<t<<": "<<ans<<"\n";
	}
}