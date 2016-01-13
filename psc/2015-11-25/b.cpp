#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool bs = 1, bq = 1, bpq = 1;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if (x == 1) {
				s.push(y);
				q.push(y);
				pq.push(y);
			} else {
				if(s.empty()){
					bs=0;bq=0;bpq=0;
					
				}else{
				bs = bs && (s.top() == y);
				bq = bq && (q.front() == y);
				bpq = bpq && (pq.top() == y);
				s.pop();
				q.pop();
				pq.pop();
			}}
		}
		cerr<<bs<<bq<<bpq<<"\n";
		if ((bs && bq) || (bs && bpq) || (bq && bpq)) {
			cout << "not sure\n";
			continue;
		}
		if((!bs)&&(!bq)&&(!bpq)){
			cout<<"impossible\n";
			continue;
		}
		if(bs){
			cout<<"stack\n";
		}else if(bq){
			cout<<"queue\n";
		}else cout<<"priority queue\n";
	}
}
