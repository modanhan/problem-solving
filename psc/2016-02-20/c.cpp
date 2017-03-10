#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
	int n,asdf=0;
	while(cin>>n){
		asdf++;
		vector<ii> v1(n,ii(0,0)),v2(n,ii(0,0));
		for(int i=0;i<n;i++){cin>>v1[i].first;v1[i].second=i;}
		for(int i=0;i<n;i++){cin>>v2[i].first;v2[i].second=i;}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		
	/*	for(int i=0;i<n;i++){
			cout<<"("<<v1[i].first<<","<<v1[i].second<<")\t";
		}cout<<endl;
		for(int i=0;i<n;i++){
			cout<<"("<<v2[i].first<<","<<v2[i].second<<")\t";
		}cout<<endl;*/
		
		for(int i=0;i<n;i++){
			if(v1[n-1-i].second!=v2[n-1-i].second){
				cout<<"Case "<<asdf<<": "<<(i+1)<<endl;
				goto done;
			}
		}
		cout<<"Case "<<asdf<<": "<<"agree"<<endl;
		done:;
	}
}