/**
 * Link: https://www.codechef.com/problems/CCBTS03
 * Chef has N laddus, i-th of which has a size s[i].
 * There are no two laddues with equal size, i.e. all the laddus have different sizes.
 * There are K children that came to meet Chef today.
 * Chef wants to give a single laddu to each of these K children.
 * Also, he wants to minimize the difference in the sizes which the children get,
 * i.e. he wants to minimize the maximum difference in the sizes of the laddus distributed.
 * This is because children feel jealous of each other if the other one has a bigger laddu that him/her.
 * 
 * Output: A single integer corresponding to the minimum difference in the sizes of the laddus distributed to the children.
 * 
 * [Hint] : Here minimum difference is required amongst every window of size k of array,
 * where diff. = max_element_in_window - min_element_in_window
 * 
 * We can sort the array at first.
 * Then we calc diff. in every window of size k
 * min diff. is the required ans. :) 
 * 
 * Also if k = 1, i.e there's only 1 children: then any size laddu will give ans as 0.
 **/
#include<bits/stdc++.h>
using namespace std;
int minimize_max_min_difference(std::vector<int> &a,int k,int n) {
    if(k==1)    return 0;

    //INT_MAX as dummy ans
    int ans = INT_MAX;
    sort(a.begin(),a.end());
    for(int i=0;i<n-k+1;++i)
        //ans = min diff. in window of size k i.e (last element - first element) of the window..
        ans = min(ans,a[i+k-1]-a[i]);
    return ans;
}