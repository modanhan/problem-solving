#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> vs(4);
	cin>>vs[0]>>vs[1]>>vs[2]>>vs[3];
	string a="",b="";
	if(vs[0][0]!='X')a+=vs[0][0];
	if(vs[0][1]!='X')a+=vs[0][1];
	if(vs[1][1]!='X')a+=vs[1][1];
	if(vs[1][0]!='X')a+=vs[1][0];
	if(vs[2][0]!='X')b+=vs[2][0];
	if(vs[2][1]!='X')b+=vs[2][1];
	if(vs[3][1]!='X')b+=vs[3][1];
	if(vs[3][0]!='X')b+=vs[3][0];
	a+=a;
//	cout<<a<<'\t'<<b<<endl;
	if(a.find(b)!=-1)cout<<"YES\n";
	else cout<<"NO\n";
}
