void binaryString(string s) {
    
    /*
        check if string can be divided into some substrings such that
        each substring has equal numver of 0s and 1s and they all make up the whole string

        e.g:
            i.) s = "0100110101"
                s can be split into
                sub = [
                    "01",
                    "0011",
                    "01",
                    "01"
                ]
                so, count = 4
           ii.) s = "0111100010"
                s can be split into 
                sub = [
                    "01",
                    "111000",
                    "10"
                ]
                so,count = 3
          iii.) s = "011110001"
                s can't be split
                since 0's count = 4
                and 1's count = 5
                so, -1
            
    */
    int n = s.length();
    int s0,s1,c;
    s0=s1=c=0;
    //we simply traverse s from start to end
    for(int i=0;i<n;++i) {
        //increase counter based on 0 and 1
        if(s[i]=='1')   s1++;
        else    s0++;
        //if anytime 0's count = 1's count, we increase counter
        if(s0==s1)  c++;
    }
    //since we visited whole string 0's count = 1's count for binary string to exist else it odes not exist
    if(s0!=s1)  cout<<-1;
    else    cout<<c;
}