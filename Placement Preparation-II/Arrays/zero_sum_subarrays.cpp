//to count subarrays with sum = 0
int countZeroSubarray(int arr[],int n){
    /*
    We use std::unordered_map when 
    > we need to keep count of some data and no ordering is required.
    > we need single element access i.e. no traversal.
    __________________________________________________________________
    Also, same as pevious we were finiding any subarray with zero sum:-
    [3,4,-1,4,3,-6,-7,-2]
         <------->
            0
    <-->
      x
    <------------>
          y
    In such case we see that: x==y
    i.e. the current sum, y already exists in memory....
    so, we store and sum up the count to previous count of this element in hashmap

    now simply increase the count of particular element in hashmap by 1
    */

    int c = 0;
    int sum = 0;
    unordered_map<int,int> m;

    for(int i=0;i<n;++i){
        m[sum]++;
        sum+=arr[i];
        if(m.find(sum)!=m.end())
            c+= m[sum];
    }

    return c;
}