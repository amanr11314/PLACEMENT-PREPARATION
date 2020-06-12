///array,size,no_of_rotations
void cyclicRotate(int arr[],int size,int m){
    int rotation = m%size;
    int temp[rotation];
    for(int i=0;i<rotation;++i){
        temp[i] = arr[i];
    }
    for(int j = rotation;j<size;++j){
        arr[j-rotation] = arr[j];
    }
    for(int i=0;i<rotation;++i){
        arr[size-rotation+i] = temp[i];
    }
}