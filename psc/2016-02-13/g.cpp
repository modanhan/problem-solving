#include <bits/stdc++.h>
using namespace std;

string s;

string v[10]={"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};
string v1[20]={
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string v2[10]={"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy",
		"eighty", "ninety"	
};

void th(string s){
	if(s[0]!='0')cout<<v[s[0]-'0']<<" hundred";
	if(s[1]=='0'&&s[2]=='0'){cout<<" thousand";goto omgwtf1;}
	if(s[0]!='0')cout<<" and ";
	if(s[1]=='1'){cout<<v1[stoi(s.substr(1,2))]<<" thousand";goto omgwtf1;}
	else if(s[1]-'0'){cout<<v2[s[1]-'0'];if(s[2]-'0')cout<<"-";}
	if(s[2]-'0')cout<<v[s[2]-'0'];
	cout<<" thousand";
	omgwtf1:;
				
	if(s.substr(3)=="000"){cout<<"\n";return;}
	if(s[3]!='0')cout<<", ";else cout<<" and ";
	if(s[3]!='0')cout<<v[s[3]-'0']<<" hundred";
	if(s[4]=='0'&&s[5]=='0'){cout<<endl;return;}
	if(s[3]!='0')cout<<" and ";
	if(s[4]=='1'){cout<<v1[stoi(s.substr(4))]<<endl;return;}
	else if(s[4]-'0'){cout<<v2[s[4]-'0'];if(s[5]-'0')cout<<"-";}
	if(s[5]-'0')cout<<v[s[5]-'0'];
	cout<<endl;
}

void meh(string s){
	if(s=="000"){cout<<"zero\n";return;}
	if(s[0]!='0')cout<<v[s[0]-'0']<<" hundred";
	if(s[1]=='0'&&s[2]=='0'){cout<<endl;return;}
	if(s[0]!='0')cout<<" and ";
	if(s[1]=='1'){cout<<v1[stoi(s.substr(1))]<<endl;return;}
	else if(s[1]-'0'){cout<<v2[s[1]-'0'];if(s[2]-'0')cout<<"-";}
	if(s[2]-'0')cout<<v[s[2]-'0'];
	cout<<endl;
}

int main(){
	while(1){
		cin>>s;
		if(s=="-1")break;
		while(s.size()%3){
			s="0"+s;
		}
		if(s.size()==9){
			if(s[0]!='0')cout<<v[s[0]-'0']<<" hundred";
			if(s[1]=='0'&&s[2]=='0'){;goto here;}
			if(s[0]!='0')cout<<" and ";
			if(s[1]=='1'){cout<<v1[stoi(s.substr(1,2))];goto here;}
			else if(s[1]-'0'){cout<<v2[s[1]-'0'];if(s[2]-'0')cout<<"-";}
			if(s[2]-'0')cout<<v[s[2]-'0'];
			here:
			cout<<" million";
			if(s.substr(3)=="000000")cout<<endl;
			else if(s.substr(3,4)=="0000"){ cout<<" and ";meh(s.substr(6));}
			else if(s.substr(3,3)=="000"){cout<<", ";meh(s.substr(6));}
			else {cout<<", ";th(s.substr(3));}
		}
		if(s.size()==6){
			th(s);
		}
		if(s.size()==3){
			meh(s);
		}
	}
}