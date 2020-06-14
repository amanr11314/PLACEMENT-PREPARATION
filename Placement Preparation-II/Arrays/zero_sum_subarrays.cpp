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
    In each iteration, we increase the count of sum in hashmap by 1
    In such case we see that: x==y
    i.e. the current sum, y already exists in memory....

    now we add up the sum with current element of array.

    Then we cheeck if sum now already exists in hashmap:
    >   Then we increase the counter to count of element in hashmap

    now simply 
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