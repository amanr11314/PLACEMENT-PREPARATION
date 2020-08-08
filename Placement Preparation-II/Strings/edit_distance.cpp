//minimum cost to convert string a -> string b
//we have 3 operations which we can perform, 
//i.) add a character 
//ii.) delete a character 
//iii.) replace a character
//cost of any of three operations is same

/**
 * Brute force way:-
 * I.  delete all characters of string a, and then add all characters of string b.
 * i.e cost = len(a)*cost of deletion + len(b)*cost of adding a character
 * 
 * II. replace all chaacters of string a, to all characters of string b.
 * i.e cost = max( len(a),len(b) )
 * 
 * Efficient Approach:- (Dynamic Programming)
 * We find miniumum of three operations:-
 * i.e cost of deleting => f(a[i-1] -> b[j])
 * cost of replacing => f(a[i-1] -> b[j-1])
 * cost of inserting => f(a[i+1] -> b[j])
 * 
 * now, the trick we see here is, if we insert a character into string a then we also have to 
 * delete the previous unmatching character from string a
 * 
 * what we do is that adding a character to string a is same as deleting the charater from string b
 * since we have inserted a charactr from string b into string a,
 * we now only need to convert string a[i] into string b[j-1]
 * 
 * i.e now cost of inserting => f(a[i],b[j-1])
 *  
 * */

void edit_distance(string a,string b,int n,int m) {
    //assuming maximum length of a and b to be 100
    int dp[101][101] = {0};
    for(int i=0;i<=m;++i)
        dp[0][i] = i;
    
    for(int i=0;i<=n;++i)
        dp[i][0] = i;
        
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];    //do not include in edit distance
            }
            else{
                dp[i][j] = 1 + min({
                    dp[i][j-1] , //insert a character of b into a. thereby, we have to convert a[i+1] -> b[j], however in this scenario,
                    //adding a character of string b into a is same as removing that character from string b since it matched...... i.e a[i] -> b[j-1] 
                    dp[i-1][j] , //delete a charcater from a 
                    dp[i-1][j-1] //replace the character from a->b
                });
            }
        }
    }
    
     
    cout<<dp[n][m]<<'\n';
}





