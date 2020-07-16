///LONGEST COMMON SUBSEQUENCE of two strings
void LCS(string a,string b,int x,int y) {
    /*
        we just check that if a[i]==a[j],
                            > then 1+LCS before including a[i] and b[j]
                                i.e. LCS[i-1][j-1]
                            else 
                            > we just count the maxiumum LCS till a[i] in sequence or b[j] in sequence
    */

    int dp[x+1][101] = {0};
    //longest common subsequence
    for(int i=1;i<=x;++i) {
        for(int j=1;j<=y;++j) {
            if (a[i-1]==b[j-1]) {
                // 1+LCS before including a[i] and b[j]
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }
    cout<<dp[x][y]<<'\n';
}