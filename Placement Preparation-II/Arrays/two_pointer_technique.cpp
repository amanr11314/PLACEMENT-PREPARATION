//We use two pointer technique i which we keep two variable pointing to 
// start and end of array and then we manipulate those pointers till low<high

//>It works on sorted array..

//e.g Pair Sum in array

//Time complexity : O(n)
bool isPairSum(int arr[],int n,int sum){
    sort(arr,arr+n);
    
    int low = 0,high = n-1;

    while(low<high){
        int s = arr[low] + arr[high];
        if(s<sum)   low++; //move to high
        else if(s>sum)  high--; //move to low
        else    return true;
    }

    return false;
}
