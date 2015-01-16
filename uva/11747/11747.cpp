#include <bits/stdc++.h>
using namespace std;

struct union_find {
	vector<int> p, r;
	union_find(int n) {
		r.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	int find(int i) {
		return p[i] == i ? i : find(p[i]);
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	void u(int i, int j) {
		if (!same(i, j)) {
			int x = find(i), y = find(j);
			if (r[x] > r[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (r[x] == r[y]) {
					r[y]++;
				}
			}
		}
	}
};

typedef pair<int, pair<int, int> > edge;
vector<int> ans;

void kruskal(int vs, vector<edge> e) {
	sort(e.begin(), e.end());
	union_find uf(vs);
	for (auto p : e) {
		if (!uf.same(p.second.first, p.second.second)) {
			uf.u(p.second.first, p.second.second);
			vs--;
		} else {
			ans.push_back(p.first);
		}
	}
}

int main() {
	int vs, es;
	cin >> vs >> es;
	do {
		ans.clear();
		if(es==0){
			cout<<"0\n";
			cin>>vs>>es;
			continue;
		}
		vector<edge> e;
		for (int i = 0; i < es; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			pair<int, int> p(u, v);
			pair<int, pair<int, int> > ps(w, p);
			e.push_back(ps);
		}
		
		kruskal(vs,e);
		
		if(ans.size()==0){
			cout<<"forest\n";
		}else{
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size()-1;i++){
				cout<<ans[i]<<" ";
			}cout<<ans[ans.size()-1]<<"\n";
		}
		
		cin >> vs >> es;
	} while (vs != 0 || es != 0);
}
