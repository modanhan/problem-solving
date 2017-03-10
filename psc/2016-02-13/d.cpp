#include <bits/stdc++.h>
using namespace std;

map<char,vector<int> > mp,t;
map<char, int> used;

int main(){
	int m,n;
	while(1){
		cin>>m>>n;
		if(m==0)break;
		mp=map<char,vector<int> >();
		for(int i=0;i<m;i++){
			char c;cin>>c;
			vector<int> v(n+1);
			for(int j=0;j<n+1;j++){
				cin>>v[j];
			}
			mp[c]=v;
			used[c]=0;
		}
		
		int ans=0;
		char ansc='.';
		// brute force on char
		for(auto p:mp){
		//	cout<<"trying "<<p.first<<endl;
			for(auto asdf:used){used[asdf.first]=0;}
			t=mp;
			char c=p.first;
			int anst=t[c][0];
			t[c][0]=0;
			//everyone else take stuff
			for(int asdf=0;asdf<2*n;asdf++){
				char cc;
				int index;
				int max=0;
				for(auto pr:t){
					if(used[pr.first]>=n)continue;
					for(int i=0;i<n+1;i++){
						if(pr.second[i]>max){
							cc=pr.first;
							max=pr.second[i];
							index=i;
						}
					}
				}
				used[cc]++;
				t[cc][index]=0;
			}
			
		/*	for(auto pr:t){cout<<pr.first<<"\t";
				for(int i=0;i<m;i++){
					cout<<pr.second[i]<<"\t";
				}cout<<endl;
			}*/
			
			char cc=c;
			int index=0;
			int max=0;
			for(auto pr:t){
				if(pr.first==c)continue;
				for(int i=0;i<n+1;i++){
					if(pr.second[i]>max){
						cc=pr.first;
						max=pr.second[i];
						index=i;
					}
				}
			}
			anst+=t[cc][index];
		//	cout<<" got "<<anst<<endl<<endl;
			if(anst>ans){
				ans=anst;
				ansc=c;
			}
		}
		cout<<ansc<<endl;
	}
	
}