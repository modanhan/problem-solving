#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> g;

int dist[20][20][20][20][4];

//up=0, left=1,
int dx[4]={0,-1,0,1},
dy[4]={1,0,-1,0};

int main(){
	cin>>n;
	g.assign(n,"");
	for(int i=n-1;i>=0;i--)cin>>g[i];
	queue<vector<int> > q;
	{q.push({0,0,0,0,0});}
	dist[0][0][0][0][0]=1;
	while(!q.empty()){
		vector<int> v=q.front();q.pop();
	//	for(int i:v)cout<<i<<' ';cout<<endl;
		int d=dist[v[0]][v[1]][v[2]][v[3]][v[4]];
		if(v[0]==n-1&&v[1]==n-1&&v[2]==n-1&&v[3]==n-1){cout<<d-1<<endl;return 0;}
		//left
		if(dist[v[0]][v[1]][v[2]][v[3]][(v[4]+1)%4]==0){
			dist[v[0]][v[1]][v[2]][v[3]][(v[4]+1)%4]=1+d;
			q.push({v[0],v[1],v[2],v[3],(v[4]+1)%4});
		}
		//right
		if(dist[v[0]][v[1]][v[2]][v[3]][(v[4]+3)%4]==0){
			dist[v[0]][v[1]][v[2]][v[3]][(v[4]+3)%4]=1+d;
			q.push({v[0],v[1],v[2],v[3],(v[4]+3)%4});
		}
		//forward
		//out of bounds.. run into wall.. already done
		{
			int px1=v[0]+dx[v[4]];
			int py1=v[1]+dy[v[4]];
			if(px1<0||px1>=n||py1<0||py1>=n){px1=v[0];py1=v[1];}
			else if(g[px1][py1]=='H'){px1=v[0];py1=v[1];}
			if(v[0]==n-1&&v[1]==n-1){px1=v[0];py1=v[1];}
			
			int px2=v[2]+dx[(v[4]+3)%4];
			int py2=v[3]+dy[(v[4]+3)%4];
			if(px2<0||px2>=n||py2<0||py2>=n){px2=v[2];py2=v[3];}
			else if(g[px2][py2]=='H'){px2=v[2];py2=v[3];}
			if(v[2]==n-1&&v[3]==n-1){px2=v[2];py2=v[3];}
			
			if(dist[px1][py1][px2][py2][v[4]]==0){
				dist[px1][py1][px2][py2][v[4]]=1+d;
				q.push({px1,py1,px2,py2,v[4]});
			}
		}
	}
}
