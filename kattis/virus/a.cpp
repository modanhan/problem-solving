#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	cin>>s1>>s2;
	int lcp=0;
	int l=min(s1.size(),s2.size());
	for(;lcp<l;lcp++){
		if(s1[s1.size()-1-lcp]!=s2[s2.size()-1-lcp])break;
	}
	int i;
	for(i=0;i<l;i++){
		if(s1[i]!=s2[i])break;
	}
	if(i+lcp>=s2.size()){
		if(s2.size()>s1.size())cout<<(s2.size()-s1.size())<<endl;
		else cout<<"0\n";
	}else{
		cout<<(s2.size()-i-lcp)<<endl;
	}
}