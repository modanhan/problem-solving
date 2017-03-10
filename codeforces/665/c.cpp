#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	for(int i=0;i<s.size();){
		int j=i+1;
		for(;j<s.size();j++){
			if(s[i]!=s[j])break;
		}
		if((j-i)%2){
			for(int k=i+1;k<j;k+=2){
				s[k]=s[i]=='a'?'b':'a';
			}
		}else{
			char c='a';
			char l=i?s[i-1]:0;
			char r=i+1==s.size()?0:s[i+1];
			while(c==l||c==r){c++;if(c>'z')c-=26;}
			for(int k=i;k<j;k+=2){
				s[k]=c;
			}
		}
		i=j;
	}
	cout<<s<<endl;
}
