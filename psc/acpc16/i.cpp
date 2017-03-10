#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            while(x--){
                int y;cin>>y;v[i]+=y;
            }
        }
        double tw=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            tw+=(n-i)*v[i];
        }printf("%9f\n",tw/n);
    }
    
}
