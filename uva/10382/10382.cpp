#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> dd;

bool cmp(dd a,dd b){
	if(a.first<b.first){
		return 1;
	}else if(a.first==b.first&&a.second>=b.second){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	double n,l,w;
	while(cin>>n>>l>>w){
		vector<dd> intervals;
		for(int i=0;i<n;i++){
			double p,r,left,right,t;
			cin>>p>>r;
			if(r*r<=w*w/4){
				continue;
			}
			t=sqrt(r*r-w*w/4);
			left=p-t;
			right=p+t;
			intervals.push_back(dd(left,right));
		}
		sort(intervals.begin(),intervals.end(),cmp);
		
		double current=0;
		int ans=0;
		for(int i=0;i<intervals.size();i++){
			if(intervals[i].first<=current){
				if(i<intervals.size()-1){
					if(intervals[i+1].first>current){
						ans++;
						current=intervals[i].second;
					}
				}else{
					if(current<l){
						ans++;
						current=intervals[i].second;
					}
				}
			}else{
				goto bad;
			}
		}
		if(current<l){
			goto bad;
		}
		cout<<ans<<"\n";
		continue;
		bad:
		cout<<"-1\n";
	}
}