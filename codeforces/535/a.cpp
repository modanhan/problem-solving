#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;cin>>x;
	vector<string> tens,ones,s;
	tens.push_back("");
	tens.push_back("ten");
	tens.push_back("twenty");
	tens.push_back("thirty");
	tens.push_back("forty");
	tens.push_back("fifty");
	tens.push_back("sixty");
	tens.push_back("seventy");
	tens.push_back("eighty");
	tens.push_back("ninety");
	
	ones.push_back("");
	ones.push_back("one");
	ones.push_back("two");
	ones.push_back("three");
	ones.push_back("four");
	ones.push_back("five");
	ones.push_back("six");
	ones.push_back("seven");
	ones.push_back("eight");
	ones.push_back("nine");
	
	s.push_back("ten");
	s.push_back("eleven");
	s.push_back("twelve");
	s.push_back("thirteen");
	s.push_back("fourteen");
	s.push_back("fifteen");
	s.push_back("sixteen");
	s.push_back("seventeen");
	s.push_back("eighteen");
	s.push_back("nineteen");
	if(x/10==0){
		if(x==0){cout<<"zero\n";return 0;}
		cout<<ones[x%10]<<"\n";
		}else
	if(x/10==1){
		cout<<s[x%10]<<"\n";
		}else{
			if(x%10==0){cout<<tens[x/10]<<"\n";return 0;}
	cout<<tens[x/10]<<"-"<<ones[x%10]<<"\n";}
}
