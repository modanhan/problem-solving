#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int i1=0,i2=0;
	while(s1[i1]=='0')i1++;
	while(s2[i2]=='0')i2++;
	if(s1.size()-i1==s2.size()-i2){
		while(i1!=s1.size()){
			if(s1[i1]>s2[i2]){
				cout<<">";
				return 0;
			}else if(s1[i1]<s2[i2]){
				cout<<"<";
				return 0;
			}
			i1++;
			i2++;
		}
		cout<<"=";
	}else if(s1.size()-i1<s2.size()-i2){
		cout<<"<";
	}else cout<<">";
}