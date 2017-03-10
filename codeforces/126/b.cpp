#include <bits/stdc++.h>
using namespace std;

int n;
string s;vector<int> z,o;

int main(){
	cin>>s;
	n=s.size();
	z.assign(n,0);
	int L=0,R=0;
	for(int i=1;i<n;i++){
		if(i>R){
			L=R=i;
			while(R<n&&s[R-L]==s[R])R++;
			z[i]=R-L;R--;
		}else{
			int k=i-L;
			if(z[k]<R-i+1){
				z[i]=z[k];
			}else{
				L=i;
				while(R<n&&s[R-L]==s[R])R++;
				z[i]=R-L;R--;
			}
		}
	}
//	for(int i=0;i<n;i++)cout<<z[i]<<' ';cout<<endl;
	for(int i=1;i<n;i++)o.push_back(z[i]);
	sort(o.begin(),o.end());
	for(int i=1;i<n;i++){
		if(i+z[i]==n&&distance(o.begin(),
		lower_bound(o.begin(),o.end(),z[i]))<n-2){
			if(z[i]){
				cout<<s.substr(0,z[i])<<endl;
				return 0;
			}
		}
	}
	cout<<"Just a legend\n";
}
