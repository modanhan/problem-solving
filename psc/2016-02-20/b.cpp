#include <bits/stdc++.h>
using namespace std;

int main(){
	int asdf=0;
	while(1){
		asdf++;
		set<int> s,l,r;
		int x;
		if(cin>>x){
			
		}else break;
		s.insert(x);
		bool omgstupid=0;
		while(1){
			cin>>x;
			if(x<0)break;
			
			if(s.count(x))omgstupid=1;
			if(omgstupid)continue;
			
			auto it=lower_bound(s.begin(),s.end(),x);
			if(it==s.end()){
				if(r.count(*s.rbegin()))omgstupid=1;
				r.insert(*s.rbegin());
				for(auto itasdf=s.begin();itasdf!=s.end();itasdf++){
					l.insert(*itasdf);
					r.insert(*itasdf);
				}
			//	cout<<"inserting "<<x<<" to very right\n";
				s.insert(x);
			}else if(it==s.begin()){
				if(l.count(*s.begin()))omgstupid=1;
				l.insert(*s.begin());
			//	cout<<"inserting "<<x<<" to very left\n";
				s.insert(x);
			}else{
				if(l.count(*it)==0){
					l.insert(*it);
			//		cout<<"inserting "<<x<<" to left of "<<*it<<"\n";
					s.insert(x);
					continue;
				}
				it--;
				if(r.count(*it)==0){
					r.insert(*it);
					it++;
					for(auto itasdf=s.begin();itasdf!=it;itasdf++){
						l.insert(*itasdf);
						r.insert(*itasdf);
					}
			//		cout<<"inserting "<<x<<" to right of "<<*it<<"\n";
					s.insert(x);
					continue;
				}
				omgstupid=1;
			}
		//	for(int i:s)cout<<i<<" ";
		//	cout<<endl;
		}
		if(omgstupid)goto bad;
		cout<<"Case "<<asdf<<": "<<"yes"<<endl;
		continue;
		
		bad:;
		cout<<"Case "<<asdf<<": "<<"no"<<endl;
	}
}