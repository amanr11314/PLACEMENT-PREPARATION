// Given a string S, find the longest palindromic substring in S. Substring of string 
// S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads 
// the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of 
// conflict, return the substring which occurs first ( with the least starting index ).

//DP Approach O(n^2)
#define MAX 10001
void longestPaliindromeSubString(string s) {
    //if mutliple longest substring exist return substring which occurs first
    int n = s.length();

    bool dp[n][MAX] = {0};
    int start = 0; 
    int maxLength = 1;

    //pre-fill dp for substring of length 1
    for(int i=0;i<n;++i)
        dp[i][i] = 1;
    
    //pre-fill dp for substring of length 2
    
    for (int i = 0; i < n - 1; ++i) { 
        if (s[i] == s[i + 1]) { 
            dp[i][i + 1] = true; 

            //keep only if first 2-length pallindromic substring
            if(maxLength!=2) {
                start = i; 
                maxLength = 2; 
            }
        } 
    } 

    //check if s[i] == s[j] and also whether dp[i+1][j-1] is also true
    //i.e a substring i...j is pallindrome if substring b/w (i+1)...(j-1) is also pallindrome

    //fill dp for substrings of length>2
    for (int l = 3; l <= n; ++l) { 
        // Fix the starting index 
        // ending index = (n-l)
        for (int i = 0; i < n - l + 1; ++i) { 
            // Get the ending index of substring from 
            // starting index i and length l
            int j = i + l - 1; 
  
            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            /*
                e.g 
                s = "abba" then s is pallindrome 
                i.) if s[0]==s[3] and 
                ii.) s.substr(1,2) is already pallindrome

                for this to work, we alread calulated if 1 length and two length 
                substrings are pallindrome or not
                ................................................................
                after generalizing s[i...j] is pallindrome if 
                >>>     (s[i]==s[j]) && (dp[i+1][j-1]==true)
            */
            if (dp[i + 1][j - 1] && s[i] == s[j]) { 
                dp[i][j] = true; 
                if (l > maxLength) { 
                    start = i; 
                    maxLength = l; 
                } 
            } 
        } 
    }
    cout<<s.substr(start,maxLength);
}

