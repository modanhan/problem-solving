#include <bits/stdc++.h>
using namespace std;

int main(){
	map<char,string> lite;
	lite['a']="@";
	lite['b']="8";
	lite['c']="(";
	lite['d']="|)";
	lite['e']="3";
	lite['f']="#";
	lite['g']="6";
	lite['h']="[-]";
	lite['i']="|";
	lite['j']="_|";
	lite['k']="|<";
	lite['l']="1";
	lite['m']="[]\\/[]";
	lite['n']="[]\\[]";
	lite['o']="0";
	lite['p']="|D";
	lite['q']="(,)";
	lite['r']="|Z";
	lite['s']="$";
	lite['t']="']['";
	lite['u']="|_|";
	lite['v']="\\/";
	lite['w']="\\/\\/";
	lite['x']="}{";
	lite['y']="`/";
	lite['z']="2";

	int c;
	while(1){
		c=getchar();
		if(c=='\n')break;
		if(isalpha(c)){
			cout<<lite[tolower(c)];
		}else{
			cout<<(char)c;
		}
	}
	cout<<endl;
	return 0;
}
