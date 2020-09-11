/**
 * Given an integer N denoting the Length of a line segment.
 * you need to cut the line segment in such a way that the cut 
 * length of a line segment each time is integer either x , y or z.
 * and after performing all cutting operation the total number of cutted segments must be maximum. 
 * 
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int a,b,c,n;

void solve() {
	
	int dp[n+1] = {0};
    dp[0] = 0;
    int x,y,z;
    for(int i=1;i<=n;++i){
        x = y =z = -1;
        if(i>=a)	//if length more than a then cut a length from it
            x = dp[i-a];
        if(i>=b)	//if length more than b then cut b length from it
            y = dp[i-b];
        if(i>=c)	//if length more than c then cut c length from it
            z = dp[i-c];
        
        //if no any length can be cut mark as -1
        if(x==-1&&y==-1&&z==-1){
            dp[i]=-1;
        }
        else{
			//else mark maximum length left after cutting either a,b or c from segment 
            dp[i] = 1 + max(max(x,y),z);
        }
    }
    cout<<dp[n]<<'\n';
 
 
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		 cin>>n;
		 cin>>a>>b>>c;
		 solve();
	}
	
	return 0;
}
