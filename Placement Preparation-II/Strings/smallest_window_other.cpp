bool hasAll(int a[],int b[]) {
    ///to check if a has all elements moe or equal to of b's

    for(int i=0;i<26;++i) 
        if(a[i]<b[i])   return false;
    
    return true;
}

///TWO POINTER + SLIDING WINDOW TECHNIQUE
void smallest_window_substr2(string &s,string &t) {
    ///Smallest window in a string containing all the characters of another string 
    int t_arr[26] = {0};
    int s_arr[26] = {0};

    int n = s.length();

    int chars = 0;
    char ch;
    
    for(int i=0;i<t.length();++i) {
        t_arr[t[i]-'a']++;
        chars++;
        ch = t[i];
    }
    
    if(chars==1){
        cout<<ch<<'\n';
        return;
    }

    int left = 0,right = 0,l=n+1;
    int mr = -1;
    while(
        (left<(n-chars+1)&&(right<=n))
    ) {
        if(hasAll(s_arr,t_arr)) {
            if(l>(right-left)) {
                l = (right-left);
                mr = left;
            }
            if(l==chars) {
                cout<<s.substr(mr,l)<<'\n';
                return;
            }
            s_arr[s[left]-'a']--;
            
            left++;
        }
        else {
            s_arr[s[right]-'a']++;
            right++;
        }
    
    }
    //if not found
    if(mr==-1)  cout<<-1<<'\n';
    
    else    cout<<s.substr(mr,l)<<'\n';

}