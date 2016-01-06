#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		vector<int> hcp(300,0),suit(300,0);
		hcp['A']=4;
		hcp['K']=3;
		hcp['Q']=2;
		hcp['J']=1;
		int p=0;
		for(int i=0;i<13;i++){
			string s;cin>>s;
			p+=hcp[s[0]];
			suit[s[1]]++;
		}
		if(p>=15&&p<=17){
		}else goto bad;
		sort(suit.begin(),suit.end());
		
		if(suit[296]==3&&suit[297]==3&&suit[298]==3&&suit[299]==4){
			
		}else if(suit[296]==2&&suit[297]==3&&suit[298]==4&&suit[299]==4){
			
		}else if(suit[296]==2&&suit[297]==3&&suit[298]==3&&suit[299]==5){
			
		}else goto bad;
		cout<<"1NT\n";
		continue;
		bad:cout<<"Pass\n";
	}
}