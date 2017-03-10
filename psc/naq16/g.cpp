#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	if(s=="1")cout<<"1\n";
	else if(s=="2")cout<<"2\n";
	else if(s=="6")cout<<"3\n";
	else if(s=="24")cout<<"4\n";
	else{
		double d=0;
		int i=1;
		while(1){
			d+=log(i)/log(10);
			int digit=floor(d)+1;
			if(digit==s.length()){
				cout<<i<<endl;return 0;
			}
			i++;
		}
	}
}
