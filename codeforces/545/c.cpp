#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> coord(n,0),height(n,0),stay(n,0),left(n,0),right(n,0);
	for(int i=0;i<n;i++){
		cin>>coord[i]>>height[i];
	}
	stay[0]=0;
	left[0]=1;
	right[0]=1;
	for(int i=1;i<n;i++){
		stay[i]=max(stay[i-1],left[i-1]);
		if(coord[i-1]+height[i-1]<coord[i]){
			stay[i]=max(stay[i],right[i-1]);
		}
		if(coord[i]-height[i]>coord[i-1]+height[i-1]){
			left[i]=right[i-1]+1;
		}
		if(coord[i]-height[i]>coord[i-1]){
			left[i]=max(left[i],max(stay[i-1],left[i-1])+1);
		}
		right[i]=max(left[i-1],stay[i-1])+1;
		if(coord[i-1]+height[i-1]<coord[i]){
			right[i]=max(right[i],right[i-1]+1);
		}
	}
/*	for(int i:stay){
		cout<<i<<"\t";
	}cout<<"\n";
	for(int i:left){
		cout<<i<<"\t";
	}cout<<"\n";
	for(int i:right){
		cout<<i<<"\t";
	}cout<<"\n";*/
	cout<<max(stay[n-1],max(left[n-1],right[n-1]))<<"\n";
}