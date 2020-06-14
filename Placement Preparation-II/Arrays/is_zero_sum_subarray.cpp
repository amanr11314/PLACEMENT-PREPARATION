//to check if there is a subarray with sum=0
bool isZeroSubarray(int arr[],int n){

    /*
    [3,4,-1,4,3,-6,-7,-2]
         <------->
            0
    <-->
      x
    <------------>
          y
    In such case we see that: x==y
    i.e. the current sum, y already exists in hashset....
    so, we simply return true;
    */
    unordered_set<int> m;
    int sum = 0;
    for(int i=0;i<n;++i){
      m.insert(sum);
      sum+=arr[i];
      if(m.find(sum)!=m.end())    return 1;
        
    }

    return false;
}