#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265
int main(){
	int t;
	cin>>t;
	int casenumber=0;
	while(t--){
	casenumber++;
		int p;
		double x,y;cin>>p>>x>>y;
		{
			double a=x-50,b=y-50;
			if(sqrt(a*a+b*b)>50){cout<<"Case #"<<casenumber<<": white\n";continue;}
			else{
				double angle=atan2(a,b)+PI;
				cout<<angle<<endl;
				if(){cout<<"Case #"<<casenumber<<": white\n";continue;}
				else{cout<<"Case #"<<casenumber<<": black\n";continue;}
			}
		}
	}
}
