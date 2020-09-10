/**
 * Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.
 * Your task is to calculate the number of paths from the upper-left square to the lower-right square 
 * where you only can move right or down.
 * Input
 * The first input line has an integer n: the size of the grid.
 * After this, there are n lines that describe the grid. Each line has n characters:
 * . denotes an empty cell, and * denotes a trap. 
 * Output
 * Print the number of paths modulo 10^9+7.
 **/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxN = 1e3,M = 1e9+7;
int n,dp[maxN][maxN];
string s[maxN];



int main() {
	cin>>n;
	for(int  i=0;i<n;++i)
		cin>>s[i];
	
	dp[0][0] = 1;
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			//if can be reached from left grid
			if(i)
				dp[i][j]+=dp[i-1][j];
			//if can be reached from left grid
			if(j)
				dp[i][j]+=dp[i][j-1];
				
			dp[i][j]%=M;
			//reset to zero if obstacle..
			if(s[i][j]=='*')
				dp[i][j] = 0;
		}
	}
	cout<<dp[n-1][n-1];
	return 0;
}
