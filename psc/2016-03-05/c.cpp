#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, lol;
vector<int> ans;
priority_queue<ii> pq;
set<int> p; //p is the set of all max height indices

int main() {
	int t;
	scanf("%i",&t);
	while (t--) {
		scanf("%i",&n);
		ans.assign(n, -1);
		p.clear();
		for (int i = 0; i < n; i++) {
			scanf("%i",&lol);
			pq.push(ii(lol, -i));
		}
		while (!pq.empty()) {
			ii top = pq.top();
			pq.pop();
			int h = top.first;
			int idx = -top.second;
			auto lb = p.lower_bound(idx);
			if (lb == p.begin()) {
				p.insert(idx);
				continue;
			}
			lb--;
			ans[idx] = *lb;
			p.insert(idx);
		}
		int asdf = 0;
		for (int i : ans) {
			if (asdf)
				printf(" ");
			if (i == -1)
				printf("X");
			else
				printf("%i", i + 1);
			asdf = 1;
		}
		printf("\n");

	}
}
