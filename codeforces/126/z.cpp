#include <bits/stdc++.h>
using namespace std;

int n;
string s;vector<int> z;

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
	for(int i=0;i<n;i++)cout<<z[i]<<' ';
	cout<<endl;
}
