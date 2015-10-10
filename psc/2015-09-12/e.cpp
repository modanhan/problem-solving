#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979
int main(){
	int n;cin>>n;
	while(n--){
		double s,r;
		cin>>s>>r;
		if(r*r>=s*s/2){
			printf("%.2f\n",s*s);
			continue;
		}
		if(r<=s/2){
			printf("%.2f\n",pi*r*r);
			continue;
		}
		double theta=acos(s/2/r);
	//	cout<<theta;
		double h=tan(theta)*s/2,ha=h*s/4;
		double arca=pi*r*r*((pi/4-theta)/pi/2)*8;
		printf("%.2f\n",ha*8+arca);
	}
}