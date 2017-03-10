#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
set<string> v;

int n,m,asdf=0;

string rmc(string s,int i){
	return s.substr(0,i)+s.substr(i+1);
}

bool bfs(string s, string t){
	set<string> st;
	queue<string> q;
	q.push(s);
	st.insert(s);
	while(!q.empty()){
		string f=q.front();
		q.pop();
		for(int i=0;i<f.size();i++){
			string nb=rmc(f,i);
			if(st.count(nb))continue;
			if(v.count(nb)){
				st.insert(nb);
				q.push(nb);
				if(nb==t)return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(cin>>n){
		asdf++;
		cout<<"Case "<<asdf<<": "<<endl;
		for(int i=0;i<n;i++){
			string x;cin>>x;
			sort(x.begin(),x.end());
			v.insert(x);
		}
		int somenum=0;
		for(auto it=v.begin();it!=v.end();it++){
			mp[*it]=somenum;
			somenum++;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			string s,t;cin>>s>>t;
			sort(s.begin(),s.end());
			sort(t.begin(),t.end());
			if(bfs(t,s)){
				cout<<"yes\n";
			}else cout<<"no\n";
		}
	}
}