#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
struct event{
	// event: 0=addtoq 1=startprocess, 2=finishprocess
	ll time,e,index,end,duration;
	event(ll a,ll b,ll c,ll d):time(a),e(b),index(c),end(d) {}
	friend bool operator>(event a,event b){
		if(a.time!=b.time)return a.time>b.time;
		return a.e<b.e;
	}
};
ll n,b,ct=0,cft=0;
priority_queue<event,vector<event>,greater<event> > pq;
queue<event> cq;
bool busy=0;
vector<ll> ans;
int main(){
	cin>>n>>b;
	ans.assign(n,-2);
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		pq.push(event(x,0,i,y));
	}
	while(!pq.empty()){
		event e=pq.top();
		ct=e.time;
		pq.pop();
	//	cout<<e.time<<'\t'<<e.e<<'\t'<<e.index<<'\t'<<e.end<<endl;
		if(e.e==0){
			//add 2q
			if(cq.size()<b){
				cq.push(event(-1,-1,e.index,e.end));
				if(!busy){
					pq.push(event(ct,1,-1,-1));
				}
			}else{
				ans[e.index]=-1;
			}
		}else if(e.e==1){
			//process
			if(cq.empty())continue;
			event pe=cq.front();
			busy=1;
			cq.pop();
			pq.push(event(ct+pe.end,2,pe.index,-1));
		}else{
			//finished
			busy=0;
			ans[e.index]=ct;
			pq.push(event(ct,1,-1,-1));
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}cout<<endl;
}
