//given an array of 0,1,2 only sort in O(n) time complexity and O(1) extra space

void dutchFlag(int arr[],int n){
    int low = 0,high=n-1,mid=0;

    while(mid<=high){
        switch(arr[mid]){

            //increase size of 0 and move 1 size ahead
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            
            //increase size of 1 and move ahead
            case 1:
                mid++;
                break;
            
            //move dcreasing towards mid
            case 2:
                swap(arr[mid],arr[high--]);
                break;
        }
        for(int i=0;i<n;++i)
            cout<<arr[i]<<' ';
        cout<<'\n';
    }
    //finally range of 0 = [0,low)
    //finally range of 1 = [low,mid)
    //finally range of 2 = [mid,n)
}