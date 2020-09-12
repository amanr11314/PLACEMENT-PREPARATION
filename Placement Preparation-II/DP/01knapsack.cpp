/**
 * You are given weights and values of N items, put these items in a knapsack of capacity W
 * to get the maximum total value in the knapsack.
 * Note that we have only "one quantity of each item". 
 * In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
 * which represent values and weights associated with N items respectively. 
 * Also given an integer W which represents knapsack capacity, 
 * find out the maximum value subset of val[] 
 * such that sum of the weights of this subset is smaller than or equal to W.
 * You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,w;
//weight,value
vector<pair<int ,int> > items;
void solve() {
    //specific weights and total weight table
	int dp[n+1][w+1];
	for(int i=0;i<=n;++i) {
		dp[i][0] = 0;
	}
	for(int i=0;i<=w;++i) {
		dp[0][i] = 0;
	}
	//iterate fro every item
	for(int i=1;i<=n;++i) {
        //iterate for every weight, for the maximium value that can be made either by inluding or not including
		for(int j=1;j<=w;++j) {
            //if current item weight is less than current total weight, then assign maximum of two choices:-
			if(items[i-1].first<=j) {
				dp[i][j] = max(
                            //include it
                            //value of current item + value by getting with weight total_curr_weight - current_item_weight  
							(items[i-1].second + dp[i-1][j-items[i-1].first]),
                            //do not include it
                            //continue with previous value...
							dp[i-1][j]
						);
			}
            //we can't include it..
            //continue with previous value..
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][w]<<'\n';
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		items.clear();
		cin>>n>>w;
		int temp;
		for(int i=0;i<n;++i){
			cin>>temp;
			items.push_back({0,temp});
		}
		for(int i=0;i<n;++i){
			cin>>temp;
			items[i].first = temp;
		} 
		solve();
	}
	
	return 0;
}
