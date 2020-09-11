/**
 * Given weights and values related to n items and the maximum capacity allowed for these items.
 * What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W
 * 
 * Here, repetitions is allowed..
 * 
 * Similiar to maximize coin change problem or maximize ribbbon cut problem
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int n,w,kval;
int val[1001];
int wt[1001];

void solve() {
	//remember similar easy version of problem are:-
	//coin change maximize problem
	//ribbon cut maximize problem
	int dp[w+1]={0}; //stores maximum value for getting to certain weight..
	for(int i=1;i<=n;++i){
		//check if weight of an item can be out of knapsack capacity
	    if(wt[i]<=w){
	        dp[wt[i]] = val[i];
	    }
	}
	
	for(int i=1;i<=w;++i) {
		kval = 0;
		for(int j=1;j<=n;++j) {
			//if less or equal to current weight, then only include it's value
			if(wt[j]<=i) {
                //value of current (weight - wt[j]) + value of current item val[j]
				kval = dp[i-wt[j]] + val[j];
				//maximize value
				dp[i] = max(dp[i],kval);
			}		
		}
	}
	
	cout<<dp[w]<<'\n';
	
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
		cin>>n>>w;
		for(int i=1;i<=n;++i)
			cin>>val[i];
		for(int i=1;i<=n;++i)
			cin>>wt[i];
		solve();
	}
	
	return 0;
}