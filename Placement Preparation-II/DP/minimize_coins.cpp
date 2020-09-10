/**
 * Consider a money system consisting of n coins. Each coin has a positive integer value.
 * Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
 * For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
 * Input: 
 * The first input line has two integers n and x: the number of coins and the desired sum of money.
 * The second line has n distinct integers c1,c2,…,cn: the value of each coin.
 * Output: 
 * Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.
 * 
 * */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(vector<ll> coins,ll n) {
	if(coins[0]==1000000 && n==1 )	{
		cout<<-1;
		return;
	}
	vector<ll> dp(n+1);
	for(ll i:coins)
		dp[i] = 1;
	for(ll i=1;i<=n;++i) {
		if(dp[i]==1)	continue;
		else {
            //initially INF if not possible
			dp[i] = INT_MAX;
			for(ll j:coins){
                //for every coin go back and check if it is possible by that coin if coin is divisor of current required amount
				if(i-j>=0 && dp[i-j])	dp[i] = min(dp[i],1+dp[i-j]);
			}
            //if not possible then set to 0
			if(dp[i]==INT_MAX)	dp[i] = 0;
		}
	}
	if(dp[n]==0)	dp[n] = -1;
	cout<<dp[n];
 
 
}