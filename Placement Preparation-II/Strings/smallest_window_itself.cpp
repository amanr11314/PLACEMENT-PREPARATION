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
    
    //hashing count of each character in string s
    for(int i=0;i<n;++i) {
        if(t_arr[s[i]-'A']==0){
            t_arr[s[i]-'A']++;
            chars++;
        }
    }
    //if chars==1 then 1 char must be in window of size 1
    if(chars==1){
        cout<<1<<'\n';
        return;
    }
    
    /*
        Now we use two pointer technique and sliding window side by side
        first, we set left = 0,right = 0
        then we keep increasing right until we find all characters of string
        now we try to increase left pointer and see if still count remains same
        if count remains same we do this again
        and if count decreaes we increase the right pointer
        
        while doing so, we also keep record of minimum window length.
        we do this till left pointer is less than (n-ditinct characters) and right
        is less than or equal to n.

        another optimizisation we do is if we find all characters and window length
        is same as number of distinct chars then simply return length.
        since this is the minimum possible size in which all distinct chars of string
        can be in 
    */

    int left = 0,right = 0,l=n+1;
    while(
        (left<(n-chars+1)&&(right<=n))
    ) {
        ///checking for all char count match
        if(hasAll(s_arr,t_arr)) {
            //setting minimum window length.
            l = min(l,right-left);
            // optimisation for window size
            if(l==chars) {
                cout<<l<<'\n';
                return;
            }
            //decrease count of char at left pointer
            s_arr[s[left]-'A']--;
            //increase left pointer
            left++;
        }
        else {
            //otherwise keep increasing right pointer 
            //increasing count of char at right pointer
            s_arr[s[right]-'A']++;
            //increasing right pointer
            right++;
        }
    
    }
    cout<<l<<'\n';


}