#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s; int a, b;
	cin >> s >> a >> b;
	vector<int> pre(s.size() - 1, -1), post(s.size() - 1, -1);

	pre[0] = (s[0] - '0')%a;
	for (int i = 1; i < pre.size(); i++){
		pre[i] = (pre[i - 1] * 10 + (s[i] - '0'))%a;
	}

	post[0] = (s[s.size() - 1] - '0')%b;
	int tens = 10;
	for (int i = 1; i < post.size(); i++){
		post[i] = (post[i - 1] + tens*(s[s.size() - i-1] - '0')) % b;
		tens = (tens * 10) % b;
	}

	for (int i = 0; i < pre.size(); i++){
		if (s[i + 1] == '0')continue;
		if (pre[i] == 0 && post[post.size() - 1 - i] == 0){
			cout << "YES\n";
			cout << s.substr(0,i+1)<<endl<<s.substr(i+1);
			return 0;
		}
	}

/*	for (int i : pre)cout << i<<" ";
	cout << endl;
	for (int i : post)cout << i<<" ";
	cout << endl;*/
	cout << "NO";
}