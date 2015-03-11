#include <iostream>
#include <string>

using namespace std;

int main(){
	int t; cin >> t;
	string a;
	getline(cin, a);
	char chars[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	while (t--){
		string l;
		getline(cin, l);
		int vow = 0, con = 0;
		for (char c : l){
			bool v = 0;
			for (char x : chars){
				if (x == c){
					vow++;
					v = 1;
					break;
				}
			}
			if (!v&&c!=' '){
				con++;
			}
		}
		cout << con << ' ' << vow << '\n';
	}
}