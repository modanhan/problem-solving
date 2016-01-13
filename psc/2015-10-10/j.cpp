#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(1){
		string line;
		getline(cin,line);
		int n=stoi(line);
		if(n==0)break;
		vector<string> v(n);
		for(int i=0;i<n;i++){
			getline(cin,v[i]);
	//		cout<<v[i]<<'\n';
		}
		int index=0;
		for(int i=0;i<n;i++){
			// i is line
			for(;index<v[i].size();){
				if(v[i][index]==' '){
					break;
				}index++;
			}
		}
		cout<<index+1<<"\n";
	}
}