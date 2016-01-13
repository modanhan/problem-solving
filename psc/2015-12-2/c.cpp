#include <bits/stdc++.h>
using namespace std;

int main(){
	double h,v;
	cin>>h>>v;// h/ans=sin(v)
	cout<<(int)ceil(h/sin(v*M_PI/180));
}