#include <bits/stdc++.h>
using namespace std;

int n,t;
vector<int> v(50,0);

vector<pair<int,int> > m;
int main(){
	cin>>n>>t;
	m.assign(n,pair<int,int>(0,0));
	for(int i=0;i<n;i++){
		cin>>m[i].first>>m[i].second;
	}
	sort(m.begin(),m.end(),greater<pair<int,int> >());
	int ans=0;
	for(auto p:m){
		int am=p.first,ti=p.second;
		while(ti>=0){
			if(v[ti]){
				ti--;
			}else{
				v[ti]=am;
				ans+=am;
				break;
			}
		}
	}
	cout<<ans<<endl;
}