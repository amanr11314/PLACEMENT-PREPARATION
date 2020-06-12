// You are given a list of n-1 integers and these integers are in the range
// of 1 to n. There are no duplicates in the list. One of the integers is
// missing in the list. Write an efficient code to find the missing integer

int missing1(int arr[],int n){
    //CAUTION: can cause overflow for large integers
    //using summation formula: n*(n+1)/2
    //sum of all integers from 1 to n - sum of given inetegrs
    int given_sum = 0;
    for(int i=0;i<n-1;++i)
        given_sum+=arr[i];
    int total_sum = n*(n+1)/2;
    int missing = total_sum - given_sum;
    return missing;
}

int missing2(int arr[],int n){
    //using xor operator ^
    //(a[1] ^ a[2] ^....a[n-1]^a[n]) ^ (a[1] ^ a[2] ^....a[n-1])
    //=>a[n-1]
    //since xor is commulative..
    //let :
    //(a[1] ^ a[2] ^....a[n-1]^a[n]) = x
    //(a[1] ^ a[2] ^....a[n-1])      = y
    //then missing integer = (x^y)

    int x = 1;
    for(int i=2;i<=n;++i)
        x^= i;
    
    int y = arr[0];
    //since (n-1) integers in the array
    for(int i = 1;i<n-1;++i)
        y^= arr[i];
    return (x^y);
}

int missing3(int arr[],int n){
    //optimised method 1
    //keep subtracting elements present in given array
    //so that size always remains in range
    int total_sum = 1;
    for(int i=2;i<=n;++i){
        //adding to total sum
        total_sum+= i;
        //subtracting already present element in array
        total_sum-=arr[i-2]; //since size of arr is (n-1) its index goes upto (n-2)
    }
    return total_sum;
}