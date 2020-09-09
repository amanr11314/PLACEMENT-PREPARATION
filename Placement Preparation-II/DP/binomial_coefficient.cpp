//To efficiently compute nCr:-
/**
 * nCr is calculated by using relation :--
 * nCr = (n-1)C(r) + (n-1)C(r-1)
 * */
//Here computing nCr mod 1e9+7
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll C[1001][801];

void solve(int n,int r) {
	if(C[n][r]) {
		cout<<C[n][r];
		return;
	}
	if(r==1) {
		cout<<n;
		return;
	}
	
	
	for(int i=1;i<=n;++i) 
		C[i][1] = i;
	 
	for(int i=2;i<=n;++i) {
		
		for(int j = 2;j<=r;++j) {
		    if(j>i) {
		        C[i][j] = 0;
		        continue;
		    }
			C[i][j] = (C[i-1][j])%mod + (C[i-1][j-1])%mod;
			C[i][j] %= mod;
			if(C[i][j]<0)   C[i][j] += mod;
		}
		
	}
	cout<<C[n][r];
}