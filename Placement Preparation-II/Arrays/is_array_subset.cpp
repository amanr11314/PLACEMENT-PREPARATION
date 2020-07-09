//To check whether second array is subset of first array
//i.e all eleemnts of arr2 are present in arr1
bool approah1(int a[],int m,int b[],int n){
    //We first sort the larger array..
    sort(a,a+m);    //O(m*log m)
    //Then we perform binary search for all elements in b[]
    //if all elements are present we return true else false
    //O(n*log m)
    for(int i=0;i<n;++i){
        //if any of the elements not found return false
        if(!binary_search(a,a+m,b[i]))  return false;
    }
    return true;
    //T = O(m*log m) + O(n*log m)
}
bool approach2(int a[],int m,int b[],int n){
    //We hash all eleemnts of larger array..
    //then look if each element of b[] is present in has or not

    unordered_set<int> h;
    
    for(int i=0;i<m;++i)    h.insert(a[i]); 
    
    for(int i=0;i<n;++i) {
        //if any of the elements not present in hash return false.
        if(h.find(b[i])==h.end())   return false;
    }
    
    return true;
}