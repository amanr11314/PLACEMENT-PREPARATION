bool check(string &s,int k){
    //utility function to check if count of each char in s is k
    int a[26]={0};
    for(int i=0;i<s.length();++i){
        a[s[i]-'a']++;
    }

    for (int i = 0; i < 26; i++) 
        if(a[i] && a[i] != k) 
            return false; 

    return true; 

}

void solve(string &s,int k) {
    // Number of Substrings with count of each character as "K".
    int n = s.length();
    int ans = 0;
    for(int i=0;i<(n-k+1);++i){

        int j = k;

        //optimisation
        //a window of size (k*m) can only have each chars repeated k times.
        // where k<=(k*m)<=n
        while((i+j)<=n) {
            string t = s.substr(i,j);
            if(check(t,k)) {
                ans++;
            }
            j+=k;
        }
    }
    cout<<ans<<'\n';
    


}