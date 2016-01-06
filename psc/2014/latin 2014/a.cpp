#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v(10,0);
	for(int i=0;i<10;i++){
		cin>>v[i];
	}
	bool ans=1;
	for(int i=0;i<5;i++){
		if(v[i]==v[i+5]){
			ans=0;
			break;
		}
	}
	cout<<(ans?"Y\n":"N\n");
}