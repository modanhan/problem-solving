#include <bits/stdc++.h>
using namespace std;

// ez game ez lyfe boiz
void gainstar();
void losestar();

int ranking=25,star=0,streak=0;
int main(){
	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]=='W'){
			streak++;
			if(streak>=3&&ranking>=6)gainstar();
			gainstar();
		}else{
			streak=0;
			losestar();
		}
	}if(ranking)cout<<ranking<<endl;
else cout<<"Legend"<<endl;
}

	void gainstar(){
		if(ranking==0)return;
		star++;
		int tstar=2;
		if(ranking<21)tstar=3;
		if(ranking<16)tstar=4;
		if(ranking<11)tstar=5;
		if(star>tstar){ranking--;star=1;}
	}
	void losestar(){
		if(ranking==0)return;
		if(ranking<21){
			star--;
			if(star==-1){
				if(ranking==20)star=0;
else{
				ranking++;
				int tstar=2;
  		        if(ranking<21)tstar=3;
   		        if(ranking<16)tstar=4;
  		        if(ranking<11)tstar=5;	
				star=tstar-1;
}
			}
		}
	}

