#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 5005
char T[MAX_N];
int SA[MAX_N],i,n,LCP[MAX_N];

void computeLCP_slow(){
	LCP[0] = 0;
	for (int i = 1; i < n; i++){
		int L = 0;
		while (T[SA[i] + L] == T[SA[i - 1] + L])L++;
		LCP[i] = L;
	}
}

bool cmp(int a, int b){
	return strcmp(T + a, T + b) < 0;
}

int main(){
	int t;
	scanf("%d\n", &t);
	while (t--){
		memset(T, 0, sizeof T);
		memset(SA, 0, sizeof SA);
		n = (int)strlen(gets(T));
		T[n++] = '$';
		for (int i = 0; i < n; i++)SA[i] = i;
		sort(SA, SA + n, cmp);
		computeLCP_slow();
		int ans = n-1-SA[1]; // n-1-SA[i] is the size of string index i in SA
		for (int i = 2; i < n; i++){
			ans += n - 1 - SA[i] - LCP[i];
		}
		printf("%d\n", ans+1);
	}
}