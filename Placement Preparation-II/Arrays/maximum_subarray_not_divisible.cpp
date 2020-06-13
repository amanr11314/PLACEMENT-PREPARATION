//maximum subarray length whose sum is not divisible by x
int fun(vector<int> arr, int n, int x){
    int sum = 0;
    for (int e : arr)
        sum += e;
    if (sum % x){
        return n;
    }
    int low = 0, high = n - 1;
    int left = sum;
    int right = sum;
    priority_queue<int> ml;
    while (low <= high){
        if (left % x != 0){
            return (high + 1);
        }
        if (right % x != 0){
            return (n - low);
        }

        left -= arr[high];
        right -= arr[low];
        low++;
        high--;
    }
    return -1;
}