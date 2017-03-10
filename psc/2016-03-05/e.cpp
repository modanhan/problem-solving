#include <bits/stdc++.h>
using namespace std;

struct attack{
public:
	double p;
	int s,r;
	attack(){}
};


int n,H,A;
vector<vector<attack> > units;

vector<vector<vector<double> > > dp; // omg

double f(int h, int a, int mask){
	if(h<=0)return 1;
	if(dp[h][a][mask]!=-1)return dp[h][a][mask];
	if(mask==((1<<n)-1))return 0;
	double ans=0;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){
			//used
		}else{
			for(int j=0;j<units[i].size();j++){
				attack x=units[i][j];
				int h1=h-max(0,x.s-a);
				int a1=a-min(x.r,a);
				ans=max(ans,x.p*f(h1,a1,mask|(1<<i))+(1-x.p)*f(h,a,mask|(1<<i)));
			}
		}
	}
	dp[h][a][mask]=ans;
	return ans;
}


int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>H>>A;
		units.assign(n,vector<attack>());
		dp.assign(H+1,vector<vector<double> >(A+1,vector<double>((1<<n),-1)));
		for(int i=0;i<n;i++){
			int ci;cin>>ci;
			while(ci--){
				attack x;
				cin>>x.p>>x.s>>x.r;
				units[i].push_back(x);
			}
		}
		printf("%.5f\n",f(H,A,0));
	}
}