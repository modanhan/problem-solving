#include <bits/stdc++.h>
using namespace std;

#define infty 104289

vector<string> m;

struct node {
public:
	int x, y, r;
	node(int a, int b, int c) {
		x = a;
		y = b;
		r = c;
	}
	void operator+=(node n) {
		x += n.x;
		y += n.y;
		r += n.r;
		r = (r + 4) % 4;
	}
};

node moves[6] = { node(0, 1, 0), node(0, -1, 0), node(1, 0, 0), node(-1, 0, 0),
		node(0, 0, -1), node(0, 0, 1) };

bool valid(node n) {
	if (n.x < 0 || n.y < 0 || n.x >= m[0].size()-1 || n.y >= m.size()-1){//cout<<"huh\n";
		return false;}
	switch (n.r) {
	case 0:
		return m[n.y][n.x + 1] != 'X' && m[n.y + 1][n.x + 1] != 'X'
				&& m[n.y + 1][n.x] != 'X';
		break;
	case 1:
		return m[n.y + 1][n.x + 1] != 'X' && m[n.y + 1][n.x] != 'X'
				&& m[n.y][n.x] != 'X';
		break;
	case 2:
		return m[n.y][n.x + 1] != 'X' && m[n.y + 1][n.x] != 'X'
				&& m[n.y][n.x] != 'X';
		break;
	case 3:
		return m[n.y][n.x + 1] != 'X' && m[n.y + 1][n.x + 1] != 'X'
				&& m[n.y][n.x] != 'X';
		break;
	}
}

int main() {
	int ro, c;
	while (1) {
		cin >> ro >> c;
		if (ro == 0 && c == 0) {
			break;
		}
		m.clear();	
		m.resize(ro);
		for (int i = 0; i < ro; i++) {
			cin >> m[i];
		}
		int x=50, y=50, r=1;
		for (int i = 0; i < ro; i++) {
			if (m[i].find("SS") != -1) {
				if (i != 0 && m[i - 1].find("S") != -1) {
					y = i - 1;
					int ss = m[i].find("SS");
					int s = m[i - 1].find("S");
					if (s > ss) {
						x = ss;
						r = 1;
					} else {
						x = s;
						r = 0;
					}
				} else {
					y = i;
					int ss = m[i].find("SS");
					int s = m[i + 1].find("S");
					if (s > ss) {
						x = ss;
						r = 3;
					} else {
						r = 2;
						x = s;
					}
				}
			}
		}

		int dx=60, dy=60, dr=3;
		for (int i = 0; i < ro; i++) {
			if (m[i].find("EE") != -1) {
				if (i != 0 && m[i - 1].find("E") != -1) {
					dy = i - 1;
					int ss = m[i].find("EE");
					int s = m[i - 1].find("E");
					if (s > ss) {
						dx = ss;
						dr = 0;
					} else {
						dx = s;
						dr = 1;
					}
				} else {
					dy = i;
					int ss = m[i].find("EE");
					int s = m[i + 1].find("E");
					if (s > ss) {
						dx = ss;
						dr = 3;
					} else {
						dr = 2;
						dx = s;
					}
				}
			}
		}

//cout<<valid(node(2,5,2));return 0;
		int dist[ro][c][4];
		for(int i=0;i<ro;i++){
			for(int j=0;j<c;j++){
			dist[i]	[j][0]=infty;
			dist[i]	[j][1]=infty;
			dist[i]	[j][2]=infty;
			dist[i]	[j][3]=infty;
			}
		}
		queue<node> q;
		q.push(node(x, y, r));
		dist[y][x][r] = 0;
		while (!q.empty()) {
			node t = q.front();
			q.pop();
	//		cout<<t.x<<' '<<t.y<<' '<<t.r<<"\n";
			for (node nei : moves) {
				nei += t;
				
				if (dist[nei.y][nei.x][nei.r] == infty && valid(nei)) {
					q.push(nei);
					dist[nei.y][nei.x][nei.r] = dist[t.y][t.x][t.r] + 1;
					if (nei.y == dy && nei.x == dx && nei.r == dr)
						goto finally;
				}
			}
		}
		cout << "IMPOSSIBLE\n";
		continue;
		finally: cout << dist[dy][dx][dr] << "\n";
	}
}
