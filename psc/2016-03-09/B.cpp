#include <bits/stdc++.h>
using namespace std;

int pos[105], rot[105], vis[105], n;

int lookFor(int val){
	for(int j=0; j<n; j++) 
		if(!vis[j] && pos[j]==val){ //i is already visited
			return j;
		}		
	return -1;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0; i<n; i++){
			pos[i] = i;
			cin >> rot[i];
		}
		for(int t=0; t<n; t++){
			memset(vis, 0, sizeof vis);				
			for(int i=0; i<n; i++) if(!vis[i]){
				vis[i] = 1;
				int idx = lookFor(pos[i]);
				if(idx!=-1 && rot[idx]!=rot[i]){
					rot[idx] = 1-rot[idx];
					rot[i] = 1-rot[i];
					vis[idx] = 1;
				}	
			}
		
			memset(vis, 0, sizeof vis);
			for(int i=0; i<n; i++) if(!vis[i]){
				vis[i] = 1; bool moved = false;				
				int idx = -1;
				if(rot[i]) idx = lookFor((pos[i]-1+n)%n);
				else 	     idx = lookFor((pos[i]+1)%n);				
				if(idx!=-1 && rot[idx]!=rot[i]){ //idx is not visited yet
					rot[idx] = 1-rot[idx];
					rot[i] = 1-rot[i];
					vis[idx] = 1;
					moved = true;
				}
				if(!moved){					
					if(rot[i]) pos[i] = (pos[i]-1+n)%n;					
					else       pos[i] = (pos[i]+1)%n;					
				}
			}
		}
		for(int i=0; i<n; i++){
			if(i>0) cout << " ";
			cout << pos[i] << " " << rot[i];			
		}
		cout << "\n";
	}
	return 0;
}
