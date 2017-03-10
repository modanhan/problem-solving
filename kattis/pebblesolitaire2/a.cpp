#include <bits/stdc++.h>
using namespace std;

string line;

vector<int> v(1<<24,50);

int f(int x){
	if(v[x]!=50)return v[x];
	int bitcount=0;
	for(int i=0;i<21;i++){
		if(((x>>i)&1)==1){
			if(((x>>(i+1))&1)==1){
				if(((x>>(i+2))&1)==0){
					goto notdone;	
				}
			}
		}
		if(((x>>i)&1)==0){
			if(((x>>(i+1))&1)==1){
				if(((x>>(i+2))&1)==1){
					goto notdone;
				}
			}
		}
	}
	for(int i=0;i<23;i++){
		if((x>>i)&1)bitcount++;
	}
	v[x]=bitcount;
	return bitcount;
	notdone:;
	
	int ans=50;
	for(int i=0;i<21;i++){
		if(((x>>i)&1)==1){
			if(((x>>(i+1))&1)==1){
				if(((x>>(i+2))&1)==0){
					int tx=x;
					tx^=1<<i;
					tx^=1<<(i+1);
					tx^=1<<(i+2);
					ans=min(ans,f(tx));
				}
			}
		}
		if(((x>>i)&1)==0){
			if(((x>>(i+1))&1)==1){
				if(((x>>(i+2))&1)==1){
					int tx=x;
					tx^=1<<i;
					tx^=1<<(i+1);
					tx^=1<<(i+2);
					ans=min(ans,f(tx));
				}
			}
		}
	}
	
	v[x]=ans;
	return ans;
	
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>line;
		int i=0;
		int x=0;
		for(char c:line){
			if(c=='o'){
				x|=1<<(22-i);
			}
			i++;
		}
		if(f(x)==50){
			cout<<23<<endl;
		}else{
		cout<<f(x)<<endl;}
	}
}