#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<pair<char, char>, int> cci;

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int d = 0;
	vector<cci> v;
	vector<char> want(n,0);
	vector<int> free(300,-1);
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			d++;
			cci c(pair<char, char>(min(a[i], b[i]), max(a[i], b[i])), i);
			v.push_back(c);
			want[i]=b[i];
			free[a[i]]=i;
		}
	}
	
	if(v.empty()){
		cout<<d<<"\n-1 -1\n";
		return 0;
	}
		
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++){
		if(v[i].first==v[i+1].first){
			if(a[v[i].second]!=a[v[i+1].second]){
				cout<<(d-2)<<"\n"<<(v[i].second+1)<<" "<<(v[i+1].second+1)<<"\n";
				return 0;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(want[i]!=0){
			if(free[want[i]]!=-1){
				cout<<(d-1)<<"\n"<<(i+1)<<" "<<(free[want[i]]+1)<<"\n";
				return 0;
			}
		}
	}
	
	cout<<d<<"\n-1 -1\n";

}
