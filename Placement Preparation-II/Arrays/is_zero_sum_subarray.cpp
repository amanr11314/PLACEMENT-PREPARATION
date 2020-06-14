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
    //also insert 0 since first element could be zero too
    m.insert(sum);
    for(int i=0;i<n;++i){
        sum+=arr[i];
        if(m.find(sum)!=m.end())    return 1;
        m.insert(sum);
    }

    return false;
}