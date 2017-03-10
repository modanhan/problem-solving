#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int> x,y,v,ansv;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		x.assign(n,0);
		y.assign(n,0);
		v.assign(n,0);
		for(int i=0;i<n;i++){cin>>x[i]>>y[i];v[i]=i;}
		int ans=100000000;
		
		do{
			int temp=0;
			for(int i=0;i<m-1;i++){
				temp+=abs(x[v[i+1]]-x[v[i]])+abs(y[v[i+1]]-y[v[i]]);
			}
			if(temp<ans){
				ans=temp;
				ansv=v;
			}
			
		//	for(int i:v)cout<<i<<" ";cout<<"\t";
		//	cout<<temp<<"\n";
		}while(next_permutation(v.begin(),v.end()));
		bool asdf=false;
		for(int i=0;i<m;i++){
			if(asdf)cout<<' ';
			cout<<ansv[i];
			asdf=true;
		}cout<<'\n';
		
	}
}