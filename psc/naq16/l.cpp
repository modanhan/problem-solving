#include <bits/stdc++.h>
using namespace std;

typedef complex<double> PX;
const PX BAD(1e100,1e100);
const double EP = 1e-9;
vector<PX> v;
struct cmpomg{
bool operator()(complex<double> a, complex<double> b)
{
    if (real(a) == real(b))
        return imag(a) < imag(b);
    return real(a) < real(b);
}};

map<PX, int, cmpomg> sortindex;
double cp(PX a, PX b) {return (conj(a)*b).imag();}
double dp(PX a, PX b) {return (conj(a)*b).real();}
bool ss(PX a, PX b) {return fabs(cp(a,b)) < EP;}

bool myWay(PX a, PX b)
{
    return sortindex[a]<sortindex[b];
}

int ccw(PX a, PX b, PX c) { 
	double r = cp(b-a, c-a);
	if (fabs(r) < EP) return 0;
	return r > 0 ? 1 : -1;
}

bool onSeg(PX p1, PX p2, PX x) { 
	return fabs(abs(p2-p1)-abs(x-p1)-abs(x-p2))<EP;
}

PX lineIntersect(PX p1, PX v1, PX p2, PX v2) {
 	if (ss(v1, v2)) return ss(v1, p2-p1) ? p1 : BAD; 
		return p1 + (cp(p2-p1,v2)/cp(v1,v2))*v1;
}

PX segIntersect(PX p1, PX p2, PX q1, PX q2) {
	if (onSeg(p1, p2, q1)) return q1;
	if (onSeg(p1, p2, q2)) return q2;
	if (onSeg(q1, q2, p1)) return p1;
	if (onSeg(q1, q2, p2)) return p2;
	PX ip = lineIntersect(p1, p2-p1, q1, q2-q1);
	return (onSeg(p1, p2, ip) && onSeg(q1, q2, ip))
		? ip : BAD;
}

double area(vector<PX> const& P) {
	double a = 0.0;
	for (int i = 0; i < P.size(); i++)
		a += cp(P[i], P[(i+1)%P.size()]);
	return 0.5 * fabs(a);
}

int main(){
	int tc;cin>>tc;
	while(tc--){
		v.assign(7,PX(0,0));
		sortindex.clear();
		for(int i=0;i<7;i++){
			double x,y;cin>>x>>y;
			v[i]=PX(x,y);
			sortindex[v[i]]=i+1;
		}
		double p;cin>>p;
		do{
			double tp=0, a=0;
			// check self intersect
			for(int i=0;i<7;i++){
				for(int j=i+2;j<7;j++){
					if((j+1)%7!=i)
					if(segIntersect(v[i],v[(i+1)%7],v[j],v[(j+1)%7])!=BAD){
						goto sfint;
					}
				}
			}

			// calc area
/*			for(int i=1;i<6;i++){
				a+=-cp(v[i]-v[0],v[i+1]-v[i]);
			}
*/
			a=area(v);
			tp=(a/4)*(a/4)*(a/4);
			sfint:;
			if(abs(p-tp)<=0.00001){
				for(int i=0;i<7;i++){
					if(sortindex[v[i]]==1)
					for(int j=0;j<7;j++)
						cout<<sortindex[v[(i+j)%7]]<<' ';
				}
				cout<<'\n';
				break;
			}
		}while(next_permutation(v.begin(),v.end(),myWay));
	}
}



