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
bool approach3(int a[],int b[],int an,int bn){

    //We use here merge like approach to check if element in b[]
    //occurs in a[] or not.

    //Sort both arrays..
    sort(a,a+an);   //O(an*log an)
    sort(b,b+bn);   //O(bn*log bn)

    int i=0,j=0;

    while(i<an && j<bn){
        //We increase both pointer if elements are equal
        if(a[i]==b[j]){
            i++;
            j++;
        }
        //if a[i]<b[j] then move pointer i till we reach the position 
        //a[i]>=b[j]
        else if(a[i]<b[j]){
            i++;
        }
        //terminate if a[i]>b[j] since, this is case when we did not
        //find the element in a[] since a is sorted, the element can't be
        //anywhere ahead in the a[].
        else{
            return false;
        }
    }

    //check if we visited and matched all elements of b[] in a[]
    return j>=bn;

}