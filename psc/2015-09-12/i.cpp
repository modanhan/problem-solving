#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<vector<int> > v(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>v[i][j];
			}
		}
		list<int> l;
		l.push_back(0);
		for(int i=1;i<n;i++){
			for(auto it=l.begin();it!=l.end();it++){
				if(v[i][*it]){
					l.insert(it,i);
					goto done;
				}
			}
			l.push_back(i);
			continue;
			done:;
		}
		for(int i:l){
			cout<<i+1<<" ";
		}cout<<"\n";
	}
}