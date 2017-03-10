#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int t;
	while(b!=0){
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int n,asdf;
int main(){
	int tc;
	cin>>tc;
	
	vector<int> totient(10001,0);
	for(int i=2;i<10001;i++){
		for(int j=1;j<i;j++){
			if(gcd(i,j)==1)totient[i]++;
		}
	}
	
	totient[1]=2;
	for(int i=2;i<10001;i++){
		totient[i]+=totient[i-1];
	}
	
	for(int t=1;t<=tc;t++){
		cin>>asdf>>n;
		cout<<asdf<<" "<<totient[n]<<endl;
	}
}