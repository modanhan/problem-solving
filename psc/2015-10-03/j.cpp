#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	string s;getline(cin,s);
	map<string,vector<string> > m;
	while(n--){
		getline(cin,s);
		stringstream buf;
		buf<<s;
		string l,r;buf>>l;
		if(m.find(l)==m.end()){
			vector<string> v;m[l]=v;
		}
		
		while(buf>>r){
			if(m.find(r)==m.end()){
						vector<string> v;m[r]=v;
					}
			m[r].push_back(l);
			m[l].push_back(r);
		}
	}
	string start,end;
	stringstream buf;
	getline(cin,s);
	buf<<s;
	buf>>start>>end;
	
	map<string,string> p;
	p[start]="randomenough";
	
	queue<string> q;
	set<string> v;
	q.push(start);
	v.insert(start);
	while(!q.empty()){
		string t=q.front();
		q.pop();
		if(t==end)goto done;
		for(string neighbour:m[t]){
			if(v.find(neighbour)==v.end()){q.push(neighbour);
				v.insert(neighbour);
				p[neighbour]=t;
			}
		}
	}
	cout<<"no route found\n";
	return 0;
	done:
	stack<string> sta;
	while(end!="randomenough"){
		sta.push(end);
		end=p[end];
	}
	while(!sta.empty()){
		cout<<sta.top()<<' ';
		sta.pop();
	}
	;
}