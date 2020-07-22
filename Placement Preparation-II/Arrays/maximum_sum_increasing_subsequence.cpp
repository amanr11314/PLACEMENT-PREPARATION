void maximum_sum_increasing_subsequence(int arr[],int n) {

    // Maximum sum increasing subsequence
    //similar to longest increaing subsequence just in place of increasing count, we increase sum
    
    int dp[n] = {0};
    dp[0] = arr[0];
    int ans = arr[0];
    for(int i=1;i<n;++i) {
        
        int j = i-1;
        while(j>=0) {
            if(arr[j]<arr[i]) {
                //storing max sum instead of max count
                dp[i] = max(dp[i],(arr[i]+dp[j]));
            }
            j--;
        }
        if(!dp[i])  dp[i] = arr[i];
    }
    for(int i=0;i<n;++i)
        ans = max(ans,dp[i]);
    cout<<ans<<'\n';
}