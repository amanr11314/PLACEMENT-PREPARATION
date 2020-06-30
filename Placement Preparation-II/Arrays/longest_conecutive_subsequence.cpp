////Refrer to algoexpert video on youtube for better explanation
//https://www.youtube.com/watch?v=ksXSDgQjL0I
//to find the longest consecutive subsequence

//best approach
void solve(int n,int arr[]){

    map<int,bool> table;
        for(int i : arr){
            table[i] = true;
        }

        int range = 0;

        int maxRange = 0;

        for(int i:arr){
            if(table[i]){
                int a = i-1;
                int b = i+1;
                // cout<<"Starting\n i = "<<i<<" a = "<<a<<'\n'<<"b = "<<b<<'\n';
                
                range = 0;
                while(table[a]){
                    //marking visited keys as false so not to visit again
                    table[a] = false;
                    a--;
                    range++;
                }
                while(table[b]){
                    //marking visited keys as false so not to visit again
                    
                    table[b] = false;
                    b++;
                    range++;
                }
                // cout<<"Now a = "<<a<<'\n'<<"b = "<<b<<'\n';
                maxRange = max(range,maxRange);
            }
        }
        cout<<maxRange;


}

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