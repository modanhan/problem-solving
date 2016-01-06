#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int> > choose(22,vector<int>(22,0));
	for(int i=0;i<22;i++){
		choose[i][0]=1;
	}
	for(int i=1;i<22;i++){
		for(int j=1;j<22;j++){
			choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
		}
	}
	int T;cin>>T;
	while(T--){
		int r,s,x,y,w;
		cin>>r>>s>>x>>y>>w;
		double p=1-(double)(r-1)/(double)s,ans=0;
		for(int i=x;i<=y;i++){
			ans+=choose[y][i]*pow(p,i)*pow(1-p,y-i);
		}
		if(ans*w-.0000001>1){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}
}