//to find maximum product in a sub - array
int maximumProductSubArray(int arr[], int n){
    /*
    to find maximum product subarray we need to focus that multiplying 2 negative number can also generate a positive number.

    since product can be large we return product mod 1000000007
    */

    if (n == 1)
        return arr[0] ;
    else{

        //initially maxProduct and minProduct are set to 1 since we need to multiply
        int maxProduct = 1;
        int minProduct = 1;
        int best = arr[0];

        for (int i = 0; i < n; i++){
            //handles case when current element is negative
            if (arr[i] < 0){
                swap(maxProduct,minProduct);
            }

            //taking mod after each multiplication
            maxProduct = max(((maxProduct % 1000000007) * (arr[i] % 1000000007)) % 1000000007, arr[i] % 1000000007);

            minProduct = min(((minProduct) % 1000000007 * (arr[i]) % 1000000007) % 1000000007, arr[i] % 1000000007);

            best = max(best % 1000000007, maxProduct % 1000000007);
        }

        return best;
    }
}