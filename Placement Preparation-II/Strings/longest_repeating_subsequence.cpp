///LONGEST REPEATING SUBSEQUENCE of a string
void LRS(string s,int n) {

    /*
        e.g. s = "ABADBEDCC"
            then LRS is longest sub-sequence of s which occurs more than 1 times
            in s in same order every times
            here, LRS(s) is ABDC
            since,
                  | | | |
                ABADBEDCC
                || |   |
        similar to LCS in same string with restriction that: 
                        if s[i]==s[j] && (i!=j)
                            then 1+LRS[i-1,j-1]
                        otherwise same as LCS
                        
    */

    int dp[n+1][1001];
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dp[i][j] = 0;

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if((s[i-1]==s[j-1])&& (i!=j)) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(
                    dp[i-1][j],dp[i][j-1]
                );
            }
        }
    }

    cout<<dp[n][n]<<'\n';
}
