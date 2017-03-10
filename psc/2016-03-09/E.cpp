#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<vector<string> > ss;
set<char> cs;
vector<char> charseq;
vector<int> ccount;
int main(){
	cin>>t;
	while(t--){
	ccount.assign(200,0);
	charseq.clear();
	cs.clear();
	
		cin>>n>>m;
		while(n--){
		string s;cin>>s;
			cs.insert(s[0]);	
			ccount[s[0]]++;
			charseq.push_back(s[0]);
		}	
		ss.assign(200,vector<string>());
		while(m--){
		string s;cin>>s;
		ss[s[0]].push_back(s);
		}
		
		for(int i=0;i<ss.size();i++){
			sort(ss[i].begin(),ss[i].end());
		
		}
		
	//	for(vector<string> a:ss){
	//		for(string s:a){cout<<s<<" ";};
	//	}
		
		if(cs.size()!=2){
		
		cout<<"No cryptic-friendly acronym\n";
		continue;
		}
		
		auto it=cs.begin();
		char c1=*it;
		it++;char c2=*it;
		if(ccount[c1]>ss[c2].size()||ccount[c2]>ss[c1].size()){
//		cout<<c1<<ccount[c1]<<ss[c1].size()<<" "<<
//		c2<<ccount[c2]<<ss[c2].size()<<endl;
		cout<<"No cryptic-ordered fragment\n";
		continue;
		}
		
		int i1=0,i2=0;bool space=0;
		for(char c:charseq){
			if(space)cout<<' ';
			space=1;
			if(c==c1){
				cout<<ss[c2][i2];
				i2++;
			}else{
				cout<<ss[c1][i1];
			i1++;
			}
		}
		cout<<'\n';
		
	}
}
