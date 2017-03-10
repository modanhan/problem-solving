#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

vector<int> lisf() {

	vector<int> p(n,-1);
	vector<int> dp(n,1);
	for(int i=1;i<n;i++){
		int m=0;
		for(int j=0;j<i;j++){
			if(v[i]>v[j]){
				if(dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
					m=v[j];
					p[i]=j;
				}else if(dp[j]+1==dp[i]&&v[j]>m){
					m=v[j];
					p[i]=j;
				}
			}
		}
	}
	int mi=0,mv=0;
	for(int i=0;i<n;i++){
		if(dp[i]>mv){
			mv=dp[i];
			mi=i;
		}else if(dp[i]=mv&&v[i]>v[mi]){
			mi=i;
		}
	}
	vector<int> ans;
	while(mi!=-1){
		ans.push_back(v[mi]);
		mi=p[mi];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		vector<int> lis = lisf();

		for (int i = 0; i < n; i++) {
			v[i] = -v[i];
		}
		vector<int> lds = lisf();
		for(int i=0;i<lds.size();i++){
			lds[i]=-lds[i];
		}
		reverse(lds.begin(),lds.end());
		
	//	for(int i:lis)cout<<i<<" ";
	//	cout<<endl;
	//	for(int i:lds)cout<<i<<" ";
	//	cout<<endl;
		
		for(int i:lis){
			lds.push_back(i);
		}
		
		v=lds;
		n=v.size();
	//	for(int i:v)cout<<i<<" ";
	//	cout<<endl;
		
		cout<<lisf().size()<<endl;
	}
}
