#include <bits/stdc++.h>
using namespace std;

int n, k;
double p;
vector<double> dp;
vector<vector<double> > d;
int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k >> p;
		dp.assign(n+1,0);
		d.assign(n+1,vector<double>(n+1,0));
		//d[i][j]=probability of using i coins get at least j heads
		for(int i=0;i<=n;i++){
			d[i][0]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=p*d[i-1][j-1]+(1-p)*d[i-1][j];
			}
		}
		//dp[i]= i coins left
		dp[k]=d[k][k];
		for(int i=k+1;i<=n;i++){
			for(int j=k;i-j>=0;j++){
				dp[i]=max(dp[i],dp[i-j]+d[j][k]);
			}
		}
		printf("Case #%i: %.9f\n",tc,dp.back());
	}
}
