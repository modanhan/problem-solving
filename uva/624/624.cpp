#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll x, n;
	while (cin >> x) {
		cin >> n;
		vector<int> v(n, 0), dp(x+1, 0),p(x+1,-1);
		dp[0]=1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int j = 0; j < n; j++) {
			for (int i = x -v[j]; i >= 0; i--) {
				if(dp[i]){
					dp[i+v[j]]=1;
					if(p[i+v[j]]==-1){
						p[i+v[j]]=v[j];
					}
				}
			}
		}
		int ans;
		for(int i=x;i>=0;i--){
			if(dp[i]){
				ans=i;
				break;
			}
		}
				
		int t=ans;
		stack<int> st;
		while(p[t]!=-1){
			st.push(p[t]);
			t-=p[t];
		}
		while(!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<"sum:"<<ans<<"\n";
	}
}
