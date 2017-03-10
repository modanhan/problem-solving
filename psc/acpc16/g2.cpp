#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

string s;
int n;

vector<vector<int> > dp;

int f(int b, int e){
    if(b==e)return 1;
    if(b>e)return 0;
    if(dp[b][e]!=-1)return dp[b][e];
    int ans=0;
    ans+=f(b+1,e)+f(b,e-1)-f(b+1,e-1);
    ans%=M;
    if(s[b]==s[e]){
        ans+=f(b+1,e-1)+1;
        ans%=M;
    }
    dp[b][e]=ans;
    return ans;
}

int main(){
    int asdf;cin>>asdf;
    while(asdf--){
        cin>>s;
        n=s.length();
        dp.assign(n, vector<int>(n,-1));
        cout<<f(0,n-1)<<endl;
    }
}
