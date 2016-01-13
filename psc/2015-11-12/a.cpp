// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=666&page=show_problem&problem=4881

#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;

VI sa, ra, lcp;
string s;char c[200000];

void csort(int l, int k) {
	int m = max(300, l+1);
	VI c(m), sa2(l);
	for (int i = 0; i < l; i++) c[i+k<l ? ra[i+k]+1 : 0]++;
	for (int s = 0, i = 0; i < m; i++) {
		swap(c[i], s); s += c[i];
	}
	for (int i = 0; i < l; i++)
		sa2[c[sa[i]+k<l ? ra[sa[i]+k]+1 : 0]++] = sa[i];
	sa = sa2;
}

void saInit() {
	int l = s.size();
	sa.resize(l);
	iota(sa.begin(), sa.end(), 0);
	ra.assign(s.begin(), s.end());
	for (int k = 1; k < l; k *= 2) {
		// To use radix sort, replace sort() with:
		 csort(l, k); csort(l, 0);
	/*	sort(sa.begin(), sa.end(), [&](int a, int b){
			if (ra[a] != ra[b]) return ra[a] < ra[b];
			int ak = a+k < l ? ra[a+k] : -1;
			int bk = b+k < l ? ra[b+k] : -1;
			return ak < bk;
		});*/
		VI ra2(l); int x = 0;
		for (int i = 1; i < l; i++) {
			if (ra[sa[i]] != ra[sa[i-1]] ||
				sa[i-1]+k >= l ||
				ra[sa[i]+k] != ra[sa[i-1]+k]) x++;
			ra2[sa[i]] = x;
		}
		ra = ra2;
	}
}

void saLCP() {
	int l = s.size();
	lcp.resize(l);
	VI p(l), rsa(l);
	for (int i = 0; i < l; i++) {
		p[sa[i]] = (i) ? sa[i-1] : -1;
		rsa[sa[i]] = i;
	}
	int x = 0;
	for (int i = 0; i < l; i++) {
		// Note: The $ condition is optional and is
		// useful for finding longest common substring
		while (p[i] != -1 && p[i]+x < l &&
			s[i+x] == s[p[i]+x] && s[i+x] != '$') x++;
		lcp[rsa[i]] = x;
		if (x) x--;
	}
}

int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		scanf("%s",c);
		s.assign(c);
		saInit();
		saLCP();
	//	for(int i=0;i<s.size();i++){
	//		cout<<i<<" "<<sa[i]<<" "<<lcp[i]<<" "<<s.substr(sa[i])<<"\n";
	//	}
		int ans=0;
		for(int i=1;i<s.size();i++){
			if(lcp[i]>lcp[i-1]){
				ans+=lcp[i]-lcp[i-1];
			}
		}
		printf("%d\n",ans);
	}
}