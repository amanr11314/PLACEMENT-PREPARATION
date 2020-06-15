//to find minimum element in a sorted rotated array with distinct elements
int findMinRotated(int a[],int n){
    int l=0,h=n-1;
    //if arr[0] < arr[n-1]  then no roation has occured..
    //so we return first element
    if(a[l]<a[h])   return a[l];

    //log(n) algorithm.. modiified binary search
	while(l<=h){
        //mid = (low+high)/2
        int m=(l+h)/2;
        //if we notice arr[mid] is less than previous element then this is smallest element
	    if(a[m]<a[m-1]){
	        return a[m];
	    }
        /*
        now there are two cases:
        i)  if arr[mid]<arr[n-1], then we need to search in left half of array
        ii)  if arr[mid]>arr[n-1], then we need to search in right half of array
        */
        
	    if(a[m]<a[n-1]){
	        h=m-1;//i)
	    }
	    else{
	        l=m+1;//ii)
	    }
	}
}