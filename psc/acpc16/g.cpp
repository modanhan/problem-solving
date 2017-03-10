#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
string s;
vector<vector<int> > dp;

int f(int b, int e){
    if(dp[b][e]!=-1)return dp[b][e];
    if(e<b+1)return 1;
    int ans=1;
    for(int i=b;i<e-1;i++){
        if(s[i]==s[e-1]){
            ans+=f(i+1,e-1);
            ans%=M;
        }
    }
    ans+=f(b,e-1);
    ans%=M;
    dp[b][e]=ans;
    return ans;
}

int main(){
    int asdf;
    cin>>asdf;
    while(asdf--){
        cin>>s;
        dp.assign(s.length()+1,vector<int>(s.length()+1,-1));
        int ans=f(0,s.length());
        ans%=M;
        cout<<ans<<endl;
    }
}
