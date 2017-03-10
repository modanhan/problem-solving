#include <bits/stdc++.h>
using namespace std;
vector<int> v(4);

int main() {
	while (1) {
		int n;
		cin>>v[0]>>v[1]>>v[2]>>v[3];
		for(n=0;n<4;n++){if(v[n]==-1)break;}
		if (v[0] == -1 && v[1] == -1 && v[2] == -1 && v[3] == -1) {
			break;
		}
		for(int ans=1;ans<=1000001;ans++){
			v[n]=ans;
			if(v[1]-v[0]==v[2]-v[1]&&v[3]-v[2]==v[2]-v[1]){
				cout<<ans<<endl;
				goto done;
			}
			if(v[1]/v[0]==v[2]/v[1]&&v[3]/v[2]==v[2]/v[1]&&
					v[1]%v[0]==0&&v[2]%v[1]==0&&v[3]%v[2]==0){
				cout<<ans<<endl;
				goto done;
			}
		}
		
		cout<<"-1\n";
		
		done:;
	}
}
