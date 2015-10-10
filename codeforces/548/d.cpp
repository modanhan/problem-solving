#include <bits/stdc++.h>
using namespace std;

class segtree {
	vector<int> st, a;
	int n;
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) + 1;
	}
	void build(int p, int l, int r) {
		if (l == r) {
			st[p] = l;
		} else {
			build(left(p), l, (l + r) / 2);
			build(right(p), (l + r) / 2 + 1, r);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (a[p1] <= a[p2]) ? p1 : p2;
		}
	}
	int rmq(int p, int l, int r, int i, int j) {
		if (i > r || j < l)
			return -1;
		if (l >= i && r <= j)
			return st[p];
		int p1 = rmq(left(p), l, (l + r) / 2, i, j);
		int p2 = rmq(right(p), (l + r) / 2 + 1, r, i, j);
		if (p1 == -1)
			return p2;
		if (p2 == -1)
			return p1;
		return (a[p1] <= a[p2]) ? p1 : p2;
	}
public:
	segtree(const vector<int>& _a) {
		a=_a;
		n=(int)a.size();
		st.assign(4*n,0);
		build(1,0,n-1);
	}
	int rmq(int i,int j) {
		return rmq(1,0,n-1,i,j);
	}

};

int main() {
	int n;cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	segtree st(v);
	
	for(int x=0;x<n;x++){
		int ans=-1;
		for(int i=0;i<n-x;i++){
			ans=max(ans,v[st.rmq(i,i+x)]);
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
}
