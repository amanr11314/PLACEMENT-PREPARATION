bool isValid(string s) {
    // https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

    // Sherlock and the Valid String

    /*
        Sherlock considers a string to be valid if all characters of the string appear
        the same number of times. It is also valid if he can remove just  character
        at index in the string, and the remaining characters will occur the same 
        number of times. Given a string , determine if it is valid
    */



    int n = s.length();
    int a[26]={0};
    for(int i=0;i<n;++i) 
        a[s[i]-'a']++;
    vector<int> arr;
    for(int i=0;i<26;++i) {
        if(a[i])
            arr.push_back(a[i]);
    }

       
    int majority = arr.front();
    int minority = arr.front();
    int f = 1;
    for(int i=1;i<arr.size();++i) {
        if(arr[i]==majority)    f++;
        else if(f==0) {
            //EXTRA
            minority = majority;
            majority = arr[i];
            f++;
        }
        else f--;
    }

    /*
        EDGE CASES:-
        i.) majority element occurs n or (n-1) times in arr
       ii.) abs(minority-majority)<=1 then only we can delete 1 character to make
            it valid string
    */

    if(
        abs(majority-minority)<=1
    )
    return  (count(arr.begin(),arr.end(),majority)>=(arr.size()-1));
    
    return false;
}