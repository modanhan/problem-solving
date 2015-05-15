#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector < vector<int> > g(n, vector<int>());
	vector<int> l(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (c == 1) {
			g[a].push_back(b);
			g[b].push_back(a);
		} else if (c == 0) {
			l[a] = 0;
			l[b] = 0;
		} else {
			l[a] = 1;
			l[b] = 1;
		}
	}
	set<int> v;
	for (int i = 0; i < n; i++) {
		v.insert(i);
	}
	while (!v.empty()) {
		queue<int> q;
		q.push(*v.begin());
		v.erase(v.begin());
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int ne:g[t]){
				if(v.find(ne)!=v.end()){
					v.erase(v.find(ne));
					q.push(ne);
					if(l[t]==-1){
						
					}else{
						if(l[ne]==-1){
							l[ne]=l[t]?0:1;
						}
						if(l[ne]==l[t]){
							cout<<"impossible\n";
							exit(0);
						}
					}
				}
			}
		}
	}
}
