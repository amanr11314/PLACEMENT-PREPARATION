/**
 * 
 * Given a gold mine (M) of n*m dimensions.
 * Each field in this mine contains a positive integer which is the amount of gold in tons.
 * Initially the miner is at first column but can be at any row. He can move only 
 * to the cell diagonally up towards the right or right or diagonally down towards the right. 
 * Your task is to find out maximum amount of gold which he can collect.
 * 
 * We simply use dp to find maximum mined gold in each column row-wise
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
const int mxN = 22;
int dp[mxN][mxN];
int M[21][21]; //given
int n,m;
int val;

//utility function for checking valid boundary of i and j
bool valid(int i,int j) {
	return (i>=0 && j>=0 && i<=n);
}

void solve(){
	int ans = 0;
    //fill for 1s coulmn as same as given matrix
	for(int i=1;i<=n;++i){
		dp[i][1] = M[i][1];
	    ans = max(ans,dp[i][1]);
	}
	//from 2nd column onwards:- 
    //we check and store maximum attainable gold from
    //[i-1][j-1] [i][j-1] [i+1][j-1]
	for(int j=2;j<=m;++j) {
		for(int i=1;i<=n;++i) {
			val = 0;
            //since already to current mine standing..
			dp[i][j] = M[i][j];
			if(valid(i-1,j-1))	val = dp[i-1][j-1];
			if(valid(i,j-1)) 	val = max(val,dp[i][j-1]);
			if(valid(i+1,j-1))	val = max(val,dp[i+1][j-1]);
            //val is maximum of previously mined..
			dp[i][j] += val;
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<'\n';
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		cin>>n>>m;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j){
				cin>>M[i][j];
			}
		}
		solve();
	}
	
	return 0;
}
