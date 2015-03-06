#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	string s;
	vector<char> v;
	cin >> s;
	cin >> s;
	for (char c : s){
		switch (c){
		case '0':
		case '1':
			break;
		case '2':
		case '3':
		case '5':
		case '7':
			v.push_back(c);
			break;
		case '4':
			v.push_back('2');
			v.push_back('2');
			v.push_back('3');
			break;
		case '6':
			v.push_back('3');
			v.push_back('5');
			break;
		case '8':
			v.push_back('2');
			v.push_back('2');
			v.push_back('2');
			v.push_back('7');
			break;
		case '9':
			v.push_back('3');
			v.push_back('3');
			v.push_back('2');
			v.push_back('7');
			break;
		}
	}
	sort(v.begin(),v.end(),greater<char>());
	for (char c : v){
		cout << c;
	}cout << "\n";
}