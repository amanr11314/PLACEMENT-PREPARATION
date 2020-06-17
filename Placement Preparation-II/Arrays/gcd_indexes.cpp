///to find gcd of index rangea given as queries
//(l,r) -> find gcd pf all elements of array in range [l,r] inclusive

#include <iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){
	
	int n, Q;
	cin>>n>>Q;

	int a[n];

	for (int i = 0; i < n; i++)
		cin>>a[i];
	
	//we precompute gcd of each possiblity into 2D array, this requires
	//O(n^2)  time complexity and O(n^2) extra space too
	int table[n][n];
	
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			if (i == j)
				table[i][j] = a[i];
			else
				table[i][j] = gcd(
					table[i][j - 1], a[j]);
		}
	
	//later query access takes O(1) time
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << "ans=" << table[l][r] << endl;
	}

	return 0;
}
/////NOTE :- best way is using Segment tree