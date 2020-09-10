/**
 * Consider a money system consisting of n coins. 
 * Each coin has a positive integer value.
 * Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
 * */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(vector<int> coins,int total) {
    //O(n^2) space and time complexity..
	int n = coins.size();
	vector<vector<int> > dp( n+1, vector<int> (total+1, 0));
	
    //first row if can be made by first coin in coin list..
	for(int i=0;i<=total;++i) {
		dp[0][i] = i%coins[0]==0;
	}
	//for remaining if not possible then without taking the coin...
    //i.e from top of table in same column
    //else sum of witout taking and with taking.. i.e dp[i][j-coinValue];
	for(int i=1;i<n;++i) {
		for(int j=0;j<=total;++j) {
			if(j==0)	dp[i][j] = 1;
			else {
				dp[i][j] = dp[i-1][j];
				if(j>=coins[i])	
					dp[i][j] += dp[i][j-coins[i]];
			}
		}
	}  
	
	cout<<dp[n-1][total]<<'\n';
 
}

int change(vector<int> coins,int total) {
    //Space optimized method..
    //O(n^2)    time complexity
    //O(n)      space complexity
    int dp[total]={0};
    dp[0] = 1;

    //iterate for every coin
    for(int coin:coins) {
        //start with coin value only.. since change cannot be made if amount is less than coin value.
        for(int i=coin;i<=total;++i)
            //since always possible to make change > coin value so, add ways to make value-coin to currrent value
            dp[i] += dp[i-coin];
    }
    return dp[total];
}