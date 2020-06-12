//Find all pairs on integer array whose sum is equal to given number.
int pair_sum(int arr[],int sum,int n){
    int c = 0;
    unordered_map<int,int> m;
    for(int j=0;j<n;++j)
        m[arr[j]]++;

    
    for(int i = 0;i<n;++i){
        //to count if corresponding all counter pair existing in hashmap
        c+= m[sum-arr[i]];
        //check for same element duplication
        if((sum-arr[i]) == arr[i]){
            //e.g sum = 4,e = 2
            //then m[2] = 1
            //in this case we don't want to count this pair atleast once
            c--;//reduce counter by 1
        }
    }
    //since we counted every pair twice, we return c/2
    return c/2;
}