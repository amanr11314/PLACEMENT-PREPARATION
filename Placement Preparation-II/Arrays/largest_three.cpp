// Given an array with all distinct elements, find the largest three
// elements. Expected time complexity is O(n) and extra space is O(1).
void printLargestThree(int arr[],int n){
    // c>b>a

    int a,b,c;
	a = b = c = INT_MIN;
	for(int i=0;i<n;++i){
        //if largest than a,b,c,
        //then 2x backwards shift to level
		if(arr[i]>c){
			a = b;
			b = c;
			c = arr[i];
		}
        //if largest than a,b,
        //then 1x backwards shift to level
		else if(arr[i]>b){
			a = b;
			b = arr[i];
		}
        //replace a with arr[i]
		else if(arr[i]>a){
			a = arr[i];
		}
	}
	cout<<c<<','<<b<<','<<a<<'\n';
}
