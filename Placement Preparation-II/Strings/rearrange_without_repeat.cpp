bool possibleRearrange(string s) {
    //Rearrange characters in a string such that no two adjacent are same
    ///Simply MOORE'S VOTING ALGORITHM works for this
    // if any of the character appears more than n/2 times then it is not possible to rearrange
    vector<int> arr;
    for(char c : s) {
        arr.push_back(c);
    }
    int majortiy = arr.front();
    int f = 1;

    for(int i=1;i<arr.size();++i) {
        if(arr[i]==majortiy)    f++;
        else if(f==0) {
            majortiy = arr[i];
            f++;
        }
        else f--;
    }
    for(int i=0;i<arr.size();++i) {
        if(arr[i]==majortiy) {
            return  !(count(arr.begin(),arr.end(),arr[i]) > (arr.size()/2));
        }
    }

    return true;
}