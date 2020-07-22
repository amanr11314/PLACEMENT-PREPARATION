void LIS(int arr[],int n) {
    // Longest Increasing Subsequence

    /*
        [ ***IMP*** ]
        edge case:    if no less than it element found as of now then  set count to 1, since still 1 length subsequence is possible    
        
        [5 8 3 7 9 1]

        we consider each element can be a single subsequence so minimum length of LIS is 1.
        now to maximize it, we just check that before it if a number is less than it then
        it will definitely form an increasing subsequence with it.
        so, we take maximum of previous ans and (1+current ans of less element) 

        let's say array is:
            [5 8 3 7 9 1]
        Then, we make a dp[] array
        and 1st element is always set to 1 since it will always form a 1 length 
        subsequence. 
        
        so, for 5,
            [ 5 8 3 7 9 1 ]
              | 
            dp->[ 1 0 0 0 0 0 ]

        for 8,
            [ 5 8 3 7 9 1 ]
            5 is less than 8 so we incrase the count to 2 since [5,8] make subsequence of length 2.
        for 3,
            no less element found so 1
            dp->[ 1 2 1 0 0 0 ]  

        for 7,
            3 is less than 7 
            so set dp->[ 1 2 1 2 0 0 ] 
            
            again, 8 is more than 7 so decrease further index.

            again, 5 is less than 7 then set maximum length with or without adding 5
            so set  dp->[ 1 2 1 2 0 0 ] since 5 makes no difference

        for 9,
            7 < 9
            so set dp->[ 1 2 1 2 3 0 ] i.e. subsequence by adding 9 to it

            again, 3 < 9, but adding 9 to 3 in subsequence makes length 2 so do not change.

            again, 8 < 9, but adding 9 to 8 in subsequence makes length 3,
                         which makes no difference in maximum, so do not change.
            similarly addin 9 to 5 in subsequence makes length = 2, so do not change.
            so dp->[ 1 2 1 2 3 0 ]
        for 1,
            no element is less than 1, 
            so dp->[ 1 2 1 2 3 1 ]
    
        so, we traverse dp[] and return maxiumum value,
            3
    */
    
    int dp[n] = {0};
    int ci = 0; 
    dp[0] = 1;
    int ans = 1;
    for(int i=1;i<n;++i) {
        
        int j = i-1;
        while(j>=0) {
            if(arr[j]<arr[i]) {
                dp[i] = max(dp[i],(1+dp[j]));
            }
            j--;
        }
        if(!dp[i])  dp[i] = 1;  //edge case:    if no less than it element found as of now then  set count to 1, since still 1 length subsequence is possible
    }
    for(int i=0;i<n;++i)
        ans = max(ans,dp[i]);
    cout<<ans<<'\n';
}