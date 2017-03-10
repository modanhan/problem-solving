#include <bits/stdc++.h>
using namespace std;

int t;
double a,b,c,d,e,f,eps=1e-9;

int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>e>>f;
		b=b-c;
		e=e-f;
		if(c+f<b+e){
			cout<<"Sonny and Alex are safe\n";
			continue;	
		}
		
		
		double ans=0;
		while(a>eps||d>eps){
			if(a<=eps||d>=100-eps){
			double time=min((100.0)/b,d/f);
			a+=time*b;
			d-=time*f;
			ans+=time;
			continue;
			}
			
			if(a>=100-eps||d<=eps){
			double time=min(100.0/e,a/c);
			a-=time*c;
			d+=time*e;
			ans+=time;
			continue;
			}
		
		
		
			double chargea=min((100.0-a)/b,a/c),
			charged=min((100.0-d)/e,d/f);
			
			
		//	cout<<chargea<<"\t"<<charged<<endl;

			if(chargea>charged){// a takes longer to go to 0 or 100, charge d
				a-=charged*c;
				d+=charged*e;ans+=charged;
			}else{
				d-=chargea*f;
				a+=chargea*b;ans+=chargea;
			
			}
			
			
		}
		cout<<(int)(ans+0.5)<<'\n';
		
	}

}
