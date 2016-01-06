#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string a;
		cin >> a;
		if (a[0] == '0') {
			cout << "Case #" << t << ": 0\n";
			continue;
		}
		if (a.size() == 1) {
			cout << "Case #" << t << ": 1\n";
			continue;
		}
		bool b = 0;
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] == '0' && a[i + 1] == '0') {
				b = 1;
				break;
			}
		}
		if (b) {
			cout << "Case #" << t << ": 0\n";
			continue;
		}
		vector<int> s;
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] == '0') {
				continue;
			}
			if (a[i + 1] == '0') {
				if (a[i] == '1') {
					s.push_back(10);
				} else if (a[i] == '2') {
					s.push_back(20);
				} else {
					b = 1;
				}
			} else {
				s.push_back(a[i] - 48);
			}
		}
		if(a[a.size()-1]!='0'){
			s.push_back(a[a.size()-1]-48);
		}
	/*	if (b) {
			cout << "Case #" << t << ": 0\n";
			continue;
		}
		if (a[a.size() - 1] == '0') {
			if (a[a.size() - 2] == '1') {
				s.push_back(10);
			} else if (a[a.size() - 2] == '2') {
				s.push_back(20);
			} else {
				b = 1;
			}
		} else {
			s.push_back(a[a.size() - 2] - 48);
			s.push_back(a[a.size() - 1] - 48);
		}
		if (b) {
			cout << "Case #" << t << ": 0\n";
			continue;
		}*/
	/*	for (int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << "\n";*/
		if(s.empty()){
			cout << "Case #" << t << ": 0\n";
			continue;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]>26){
				cout << "Case #" << t << ": 0\n";
				b=1;
				break;
			}
		}
		if(b){
			cout << "Case #" << t << ": 0\n";
			continue;
		}
		vector<ll> dp(200, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= s.size(); i++) {
			dp[i] = dp[i - 1];
			if (s[i - 2] < 3 && s[i - 1] < 7) {
				dp[i] += dp[i - 2];
			}
		}
		cout << "Case #" << t << ": " << dp[s.size()] << "\n";
	}
}
