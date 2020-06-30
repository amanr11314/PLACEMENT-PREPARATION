////Refrer to algoexpert video on youtube for better explanation
//https://www.youtube.com/watch?v=ksXSDgQjL0I
//to find the longest consecutive subsequence
int longestConcesutiveSubSequence(int arr[],int n){
    /*
    Find the length of the longest sub-sequence such that elements in the 
    subsequence are consecutive integers, the consecutive numbers can 
    be in any order
    */
    unordered_map<int,int> mp;
    //first we sort the array
    sort(arr,arr+n);
    //store count as 1 default..
    int c = 1;
    /*
    we store each number into hashma with count = 1 initially.
    Also we ignore dulpicate elements
    then we check if previous element of this key exists in map
    if yes then we add the count to previous element's count

    finally we update count c to max value b/w c and new count value of key in hashmap
    */
    for(int i=0;i<n;++i){
        if(arr[i]==arr[i-1])    continue;
        mp[arr[i]] = 1;
        if(mp.find(arr[i]-1)!=mp.end()){
            int val = mp[arr[i]-1];
            mp[arr[i]]+=val;
            c = max(c,mp[arr[i]]);
        }
    }
    return c;
}

//another way is using hashing elements into hashset

// Returns length of the longest contiguous subsequence
int findLongestConseqSubseq(int arr[], int n){
    unordered_set<int> S;
    S.clear();
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    // check each possible sequence from the start
    // then update optimal length
    for (int i=0; i<n; i++){
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i]-1) == S.end()){
            // Then check for next elements in the
            // sequence
            int j = arr[i];
            //go till next element in this equence is found continuosly...
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if this length
            // is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}