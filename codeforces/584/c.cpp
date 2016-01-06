#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;cin>>n>>t;
	string a,b;cin>>a>>b;
	int d=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])d++;
	}
	//construct from similarities
	int s=n-d;
	int w=n-t;
	//want w to be same, already has s same
	string ans=a;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
		if(a[i]!='a'&&b[i]!='a')ans[i]='a';
		if(a[i]!='b'&&b[i]!='b')ans[i]='b';
		if(a[i]!='c'&&b[i]!='c')ans[i]='c';
	}}
	if(s>=w){
		int diff=s-w;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				if(a[i]!='a'&&b[i]!='a')ans[i]='a';
				if(a[i]!='b'&&b[i]!='b')ans[i]='b';
				if(a[i]!='c'&&b[i]!='c')ans[i]='c';
			}else{
				if(diff){
					if(a[i]!='a'&&b[i]!='a')ans[i]='a';
					if(a[i]!='b'&&b[i]!='b')ans[i]='b';
					if(a[i]!='c'&&b[i]!='c')ans[i]='c';
					diff--;
				}
			}
		}
	}else{
		if((w-s)*2>d){cout<<-1;return 0;}
		int i=0;bool changea=1;int need=0;
		while(i!=n){
			if(need!=(w-s)*2){
				if(a[i]!=b[i]){
					if(changea){
						ans[i]=b[i];
						changea=0;
					}else{
						ans[i]=a[i];
						changea=1;
					}need++;
				}
			}
			i++;
		}
	}
	cout<<ans;
}