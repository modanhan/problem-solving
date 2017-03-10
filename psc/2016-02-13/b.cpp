#include <bits/stdc++.h>
using namespace std;

double d, h, x, n1, n2;

void f() {
	double lower=.00001,upper=M_PI/2,phi;
	while(upper-lower>.00001){
		phi=(lower+upper)/2;
		double px=x-d/tan(phi);
		// surface to plane vector = (-px,h)
		double theta1=M_PI/2-phi,theta2=asin(sin(theta1)*(n2/n1));
		double a=atan(px/h);
		if(a>theta2){
			upper=phi;
		}else{
			lower=phi;
		}
	}
	printf("%.2f\n",(phi/M_PI*180));
}

int main() {
	while (1) {
		cin >> d >> h >> x >> n1 >> n2;
		if (d == 0)
			break;
		f();
	}
}
