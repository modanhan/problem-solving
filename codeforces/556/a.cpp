#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	string st;cin>>n>>st;
	stack<int> s;
	for(int i=0;i<n;i++){
		if(!s.empty()&&s.top()!=st[i]){
				s.pop();
		}else{
			s.push(st[i]);
		}
	}
	cout<<s.size()<<"\n";
}