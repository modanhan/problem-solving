#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,q;

vector<int> o;
vector<int> A;

int sum(int i) // Returns the sum from index 1 to i
{
    int sum = 0;
    while(i > 0) 
        sum += A[i], i -= i & -i;
    return sum;
}
 
void add(int i, int k) // Adds k to element with index i
{
    while (i < n) 
        A[i] += k, i += i & -i;
}

int main(){
	cin>>n>>k>>>a>>b>>q;

	while(q--){
		int x;cin>>x;
		if(x==1){
			int di,ai;cin>>di>>ai;
			o[di]+=ai;
			add(di,ai);
		}else{
			int r;cin>>r;
			
		}
	}
}