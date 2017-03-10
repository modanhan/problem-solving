#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> v,p;

int x(int b, int e){//=v[b]^v[b+1]^...^v[e]
	if(b==0)return p[e];
	return p[e]^p[b-1];
}

int main(){
	cin>>n>>m>>k;
	v.assign(n,0);
	p.assign(n,0);
	cin>>v[0];
	p[0]=v[0];
	for(int i=1;i<n;i++){
		cin>>v[i];
		p[i]=v[i]^p[i-1];
	}
	
}























// jerome is the best