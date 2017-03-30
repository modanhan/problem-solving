#include <bits/stdc++.h>
using namespace std;

string s;

int num(int idx,int l){
	int ans=0;
	for(int i=idx;i<idx+l;i++){
		ans<<=1;
		if(s.at(i)=='H')ans++;
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		for(int a=20;a>0;a--){
			if((1<<a)*a>s.size())continue;
			int ans=8137246;
			
			for(int offset=0;offset<a;offset++){
                if(offset+(1<<a)*a>s.size())break;
				vector<int> occ(1<<a,0);
				int unique=0;
				int i=offset;
				for(int j=0;j<(1<<a);j++){
					int x=num(i,a);
					if(occ.at(x)==0)unique++;
					occ.at(x)++;
					i+=a;
				}
				if(unique==1<<a){ans=offset;break;}
				while(i+a<=s.size()){
					int prev=num(i-(1<<a)*a,a);
					int ths=num(i,a);
					if(occ.at(prev)==1)unique--;
					if(occ.at(ths)==0)unique++;
					occ.at(prev)--;
					occ.at(ths)++;
				
					if(unique==1<<a){ans=min(ans,(i-(1<<a)*a+a));break;}
				
					i+=a;
				}
			}
			
			if(ans!=8137246){
				cout<<a<<" "<<ans<<'\n';
				break;
			}
		}
	}
}

