#include <bits/stdc++.h>
using namespace std;

int n,a,b,T;
string s;

int moveright(){
	int t=T,i=1;
	while(t>=0){
		t-=a;
		t-=s[i]=='w'?b:0;
		t--;
		i++;
	}
	if(i>n)return n;
	int ans=i-1;
	t-=i*a-a;
	int k=0;
	for(int j=0;j<i;j++){
		// remove s[i-j-1]
		t+=a+(s[i-j-1]=='w'?b:0)+1;
		while(t>=0){
			ans=max(ans,i-j+k);
			t-=a+(s[n-k-1]=='w'?b:0)+1;
			k++;
		}
	}
	return ans;
}

int moveleft(){
	int t=T,i=1;
	while(t>=0){
		t-=a;
		t-=s[n-i]=='w'?b:0;
		t--;
		i++;
	}
	if(i>n)return n;
	int ans=i-1;
	t-=i*a-a;
	int k=0;
	for(int j=0;j<i;j++){
		// remove s[n-i+j]
		t+=a+(s[n-i+j]=='w'?b:0)+1;
		while(t>=0){
			ans=max(ans,i-j+k);
			t-=a+(s[k]=='w'?b:0)+1;
			k++;
		}
	}
	return ans;
}

int main(){
	cin>>n>>a>>b>>T>>s;
	T-=s[0]=='w'?b:0;
	T--;
	if(T<0){cout<<"0\n";return 0;}
	cout<<max(moveright(),moveleft())<<endl;
}
