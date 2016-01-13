#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string x; cin >> x;
	stack<char> s;
	int ans = 0;
	for (int i = 0; i < x.size(); i++){
		char c = x[i];
		if (c == '<' || c == '(' || c == '[' || c == '{')
			s.push(c);
		else{
			if (s.empty()){
				cout << "Impossible";
				return 0;
			}
			if (c-s.top()>0&&c-s.top()<=2){
				
			}
			else { ans++; }
			s.pop();
		}

	}
	if (s.empty())
	cout << ans;
	else cout << "Impossible";
	
}