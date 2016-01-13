#include <bits/stdc++.h>
using namespace std;

int main(){
	int t=1,a,b,c,d;
	while(cin>>a>>b>>c>>d){
		cout<<"Case "<<t<<":\n";
		int det=(a*d-b*c);
		cout<<d/det<<" "<<(-b/det)<<"\n"<<(-c/det)<<" "<<
				a/det<<"\n";
		t++;
	}
}