//This algorithm is also based on two pointer technique.

bool find3Sum(int arr[],int n,int sum){

    sort(arr,arr+n);

    for(int i=0;i<n;++i){
        int low = i+1,high = n-1;

        while(low<high){
            int s = arr[low] + arr[i] + arr[high];

            if(s<sum)   low++;//move to high
            else if(s>sum)  high--; //move to low
            else    return true;
        }

    }
    return false;
}