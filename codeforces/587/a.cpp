#include <bits/stdc++.h>
using namespace std;

vector<bool> v(1002001,0);


int main(){
	int n;scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		while(v[x]){
			v[x]=0;x++;
		}v[x]=1;
	}
	
	int ans=0;
	for(int i=0;i<1002001;i++){
		if(v[i])ans++;
	}
	cout<<ans;
	
}