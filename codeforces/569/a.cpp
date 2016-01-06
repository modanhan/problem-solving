#include <iostream>
using namespace std;


int main(){
	double t, s, q; cin >> t >> s >> q;
	double d=s, ans = 1;
	while (d < t){
		double time = (d)/(1-(q-1)/q);
	//	cout << time << " " << t<<" " << (time >= t) << "\n";
		if (time >= t-.0000000001){
			break;
		}else{
			d = time;
			ans++;
		}
	}
	cout << ans<<"\n";
}