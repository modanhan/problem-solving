#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int asdf=1;asdf<=t;asdf++){
        int r,c;
        cin>>r>>c;
        vector<string> v(r);
        for(int i=0;i<r;i++)cin>>v[i];
        cout<<"Test "<<asdf<<endl;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
}
