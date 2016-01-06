#include <bits/stdc++.h>
using namespace std;

int main(){
	string l;
	while(1){
		cin>>l;
		if(l==".")break;
		int i=1;
		for(;i<l.size();i++){
			if(l.size()%i)continue;
			for(int m=i;m<l.size();m++){
				if(l[m]!=l[m%i])goto bad;
			}
			goto good;
			bad:;
		}
		good:cout<<(l.size()/i)<<'\n';
	}
}