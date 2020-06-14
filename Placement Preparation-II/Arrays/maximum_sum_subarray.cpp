//to print maximum sum of a subarray in given array.
//also known as kadane's algoritm
int maxSumSubarray(int arr[],int n){
    //we first store current sum and maximum sum as first elemeent of array
    int cur_sum = arr[0];
	int max_sum = arr[0];
    /*
    then we store current sum as max of :
                    [cummulative sum with currrent element] 
                      and 
                    [only current element]
    then we again store maximum sum as max of:
                    [current sum calculated]
                     and
                    [previous maximum sum]
    */
	for(int i=1;i<n;++i){
	    int e = arr[i];
	    cur_sum = max(e,cur_sum+e);
	    max_sum = max(max_sum,cur_sum);
	}
	return max_sum;
}