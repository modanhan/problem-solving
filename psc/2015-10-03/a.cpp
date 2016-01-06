#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ctoi(char c){
	if(c<='9')return c-'0';
	else return c-'a'+10;
}

char itoc(int i){
	if(i<=9)return i+'0';
	else return i+'a'-10;
}

char itobase(int i){
	if(i<=9)return i+'0';
	else if(i==36)return '0';
	else return i+'a'-10;
}

int main(){
	int T;cin>>T;
	string l;getline(cin,l);
	while(T--){
		getline(cin,l);
		stringstream in;
		in<<l;
		string x,op,y,eq,z;
		in>>x>>op>>y>>eq>>z;
		vector<int> goodbases;
		for(char c:x){
			if(c!='1')goto not1;
		}
		for(char c:y){
			if(c!='1')goto not1;
		}
		for(char c:z){
			if(c!='1')goto not1;
		}
		switch(op[0]){
		case '+':if(x.size()+y.size()==z.size())goodbases.push_back(1);
			break;
		case '-':if(x.size()-y.size()==z.size())goodbases.push_back(1);
			break;
		case '*':if(x.size()*y.size()==z.size())goodbases.push_back(1);
			break;
		case '/':if(y.size()*z.size()==x.size())goodbases.push_back(1);
			break;
		}
		not1:
		for(int base =2;base<37;base++){
			ll xval=0,yval=0,zval=0;
			ll exp=1;
			for(int i=x.size()-1;i>=0;i--){
				if(ctoi(x[i])>=base)goto bad;
				xval+=ctoi(x[i])*exp;
				exp*=base;
			}
			exp=1;
			for(int i=y.size()-1;i>=0;i--){
				if(ctoi(y[i])>=base)goto bad;
				yval+=ctoi(y[i])*exp;
				exp*=base;
			}
			exp=1;
			for(int i=z.size()-1;i>=0;i--){
				if(ctoi(z[i])>=base)goto bad;
				zval+=ctoi(z[i])*exp;
				exp*=base;
			}
		//	cout<<"base"<<base<<' '<<xval<<' '<<yval<<' '<<zval<<'\n';
			switch(op[0]){
			case '+':if(xval+yval==zval)goto good;
				break;
			case '-':if(xval-yval==zval)goto good;
				break;
			case '*':if(xval*yval==zval)goto good;
				break;
			case '/':if(yval*zval==xval)goto good;
				break;
			}goto bad;
			good:
			goodbases.push_back(base);
			bad:;
		}
		if(goodbases.empty()){
			cout<<"invalid\n";continue;
		}
		for(int i:goodbases){
			cout<<itobase(i);
		}cout<<'\n';
	}
}