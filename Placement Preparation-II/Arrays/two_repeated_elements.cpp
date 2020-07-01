//to find two repeating elements in array.
//given an array of (n+2) integers where exactly two element srepeat twice 
//print them in their order of repetition.

#define MAX 100001

int arr[MAX];

// input in array..

for(int i=0;i<n+2;i++) {
    if(arr[abs(arr[i])]>0)
        arr[abs(arr[i])]=-arr[abs(arr[i])];
    else
        cout<<abs(a[i])<<" ";
}