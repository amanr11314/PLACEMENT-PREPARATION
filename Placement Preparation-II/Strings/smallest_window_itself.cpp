bool hasAll(int a[],int b[]) {
    ///to check if a has all elements moe or equal to of b's

    for(int i=0;i<26;++i) 
        if(a[i]<b[i])   return false;
    
    return true;
}

///TWO POINTER + SLIDING WINDOW TECHNIQUE
void smallest_window_substr(string &s) {
    ///smallest window length containing all the distinct characters of itself
    int t_arr[26] = {0};
    int s_arr[26] = {0};

    int n = s.length();

    int chars = 0;
    
    for(int i=0;i<n;++i) {
        if(t_arr[s[i]-'A']==0){
            t_arr[s[i]-'A']++;
            chars++;
        }
    }
    if(chars==1){
        cout<<1<<'\n';
        return;
    }
    
    int left = 0,right = 0,l=n+1;
    while(
        (left<(n-chars+1)&&(right<=n))
    ) {
        if(hasAll(s_arr,t_arr)) {
            l = min(l,right-left);
            if(l==chars) {
                cout<<l<<'\n';
                return;
            }
            s_arr[s[left]-'A']--;
            
            left++;
        }
        else {
            s_arr[s[right]-'A']++;
            right++;
        }
    
    }
    cout<<l<<'\n';


}