//sorting an array using quick sort algorithm


int partition1(int arr[],int start,int end){
    //pivot as last element
    int pivot = arr[end];
    int i = start -1;
    for(int j = start;j<end;++j){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1; //arr[i+1] is now at its correct place
}

int partition2(int arr[],int start,int end){
    //pivot as first element
    int pivot = arr[start];
    int i = end + 1;
    for(int j = end;j>start;--j){
        if(arr[j]>pivot){
            i--;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i-1],arr[start]);
    return i-1; //arr[i-1] is now at its correct place
}

///initially call by start = 0,end = size-1
void quickSort(int arr[],int start,int end){
    if(start<end){
        int pi = partition1(arr,start,end);
        // int pi = partition2(arr,start,end);
        quickSort(arr,start,pi-1);
        quickSort(arr,pi+1,end);
    }
}