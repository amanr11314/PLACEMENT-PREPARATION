// Find the first repeating element in an array of integers.
int firstRepeating(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        int e = arr[i];
        if(mp[e]){
            return e;
        }
        mp[e]++;
    }
    return -1;
}