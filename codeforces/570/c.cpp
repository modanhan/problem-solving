#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
	string s;
	int n, m,dots=0,segs=0; cin >> n >> m>>s;
	bool inseg = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '.'){
			dots++;
			if (!inseg){
				inseg = 1;
				segs++;
			}
		}
		else{
			if (inseg){
				inseg = 0;
			}
		}
	}
//	cout << dots << " " << segs << '\n';
	if (n == 1){
		while (m--){
			int index; char c;
			cin >> index >> c;
			cout << "0\n";
		}
		return 0;
	}
	while (m--){
		int index; char c;
		cin >> index >> c;
		index--;
		if (c == '.'){
			if (s[index] != '.'){
				dots++;
				if (index == 0){
					if (s[1] != '.'){
						segs++;
					}
				}
				else if (index == n - 1){
					if (s[n - 2] != '.'){
						segs++;
					}
				}
				else{
					if (s[index - 1] == '.'){
						if (s[index + 1] == '.'){
							segs--;
						}
					}
					else{
						if (s[index + 1] != '.'){
							segs++;
						}
					}
				}
			}
		}
		else{
			if (s[index] == '.'){
				dots--;
				if (index == 0){
					if (s[1] != '.'){
						segs--;
					}
				}
				else if (index == n - 1){
					if (s[n - 2] != '.'){
						segs--;
					}
				}
				else{
					if (s[index - 1] == '.'){
						if (s[index + 1] == '.'){
							segs++;
						}
					}
					else{
						if (s[index + 1] != '.'){
							segs--;
						}
					}
				}
			}
		}
		s[index] = c;
		cout << dots- segs << '\n';
	}
}