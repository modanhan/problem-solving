#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> ans;
	for(int i=0;i<n;i++){
		bool good=1;
		for(int j=0;j<n;j++){
			int x;cin>>x;
			if(x==1||x==3){
				good=0;
			}
		}
		if(good){
			ans.push_back(i+1);
		}
	}
	cout<<ans.size()<<"\n";
	for(int i:ans){
		cout<<i<<" ";
	}
	cout<<"\n";
}