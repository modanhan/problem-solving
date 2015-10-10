#include <bits/stdc++.h>
using namespace std;

class dice{
public:
	int u=0,d=0,l=0,r=0,f=0,b=0;
	void n(){
		int t=u;
		u=f;f=d;d=b;b=t;
	}
	void s(){
		int t=u;
		u=b;b=d;d=f;f=t;
	}
	void w(){
		int t=u;
		u=r;r=d;d=l;l=t;
	}
	void e(){
		int t=u;
		u=l;l=d;d=r;r=t;
	}
};

int main(){
	int n,m,p;cin>>n>>m>>p;
	vector<vector<int> > v(n,vector<int>(n,0));
	while(m--){
		int x,y,t;cin>>x>>y>>t;
		x--;y--;v[x][y]=t;
	}
	string s;cin>>s;
	dice d;
	int px=0,py=0,i=0;
	for(;i<p;i++){
		char c=s[i];
		switch(c){
		case 'N':
			py++;
			if(py>=n)goto bad;
			d.n();
			break;
		case 'E':
			px++;
			if(px>=n)goto bad;
			d.e();
			break;
		case 'W':
			px--;
			if(px<0)goto bad;
			d.w();
			break;
		case 'S':
			py--;
			if(py<0)goto bad;
			d.s();
			break;
		}
	//	cout<<d.d<<' '<<v[px][py]<<' '<<px<<' '<<py<<'\n';
		if(d.d==0){
			d.d=v[px][py];
		}else if(v[px][py]!=0&&d.d!=v[px][py]){
			goto bad;
		}
		if(d.u!=0&&d.d!=0&&d.l!=0&&d.r!=0&&d.f!=0&&d.b!=0){
			goto done;
		}
	}
	goto bad;
	done:
	for(;i>=0;i--){
		switch(s[i]){
		case 'N':
			d.s();
			break;
		case 'E':
			d.w();
			break;
		case 'W':
			d.e();
			break;
		case 'S':
			d.n();
			break;
		}
	}
	cout<<d.u<<' '<<d.r<<' '<<d.b<<' '<<d.f<<' '<<d.l<<' '<<d.d<<'\n';
	return 0;
	bad:
	cout<<"0 0 0 0 0 0\n";
	return 0;
}