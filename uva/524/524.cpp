#include <bits/stdc++.h>
using namespace std;

vector<int> prime(50,1);
int n,c=1;

void f(vector<int> ans,vector<int> used){
	if(ans.size()==n){
		if(prime[ans.front()+ans.back()]){
			for(int i=0;i<n-1;i++){
				cout<<ans[i]<<" ";
			}
			cout<<ans.back();
			cout<<"\n";
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&prime[ans.back()+i]){
			used[i]=1;
			ans.push_back(i);
			f(ans,used);
			ans.pop_back();
			used[i]=0;
		}
	}
}

int main(){
	prime[0]=0;prime[1]=0;
	for(int i=2;i<50;i++){
		if(prime[i]){
			for(int j=i*i;j<50;j+=i){
				prime[j]=0;
			}
		}
	}
	while(cin>>n){
		if(c>1){
			cout<<"\n";
		}
		cout<<"Case "<<c<<":\n";
		vector<int> used(n+1,0),ans;
		ans.clear();
		ans.push_back(1);
		used[1]=1;
		f(ans,used);
		c++;
	}
}