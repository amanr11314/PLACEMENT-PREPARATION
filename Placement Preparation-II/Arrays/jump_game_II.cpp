/**
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position. 
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 * 
 * Pretty Easy Greedy Solution if you understand it :p 😁
 * 
 * Problem Link: https://leetcode.com/problems/jump-game-ii/
 * 
 * Modified question from GFG: https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
 * 
 * Awesome Explanation: https://www.youtube.com/watch?v=vBdo7wtwlXs 
 * 
 **/
#include <bits/stdc++.h>
using namespace std;
int minimum_jumps(vector<int> arr)
{
    size_t n = arr.size();

    //no jump required for single sized array
    if (n <= 1)
        return 0;

    //always keep chosing maxlength ladder
    int ladder = arr[0];

    //when stairs end from current ladder and no the end of array and still ladder goes till end set stairs of that ladder
    int stairs = arr[0];

    //required jump(s) to reach the end of array
    int jumps = 1;

    for (int i = 1; i < n; ++i)
    {
        //if alreday end return jumps
        if (i == n - 1)
            return jumps;

        //chose biggest ladder
        ladder = max(ladder, i + arr[i]);

        //stairs decrease as we move ahead
        stairs--;

        //no stairs left
        if (stairs == 0)
        {
            //means need to jump from 1 ladder to another
            ++jumps;

            //if actually ladder is big enough (in case 0 stairs on some ladder)
            if (i < ladder)
            {
                stairs = ladder - i;
            }
            else
            {
                //we ladder isn't big enough to reach till this end of stair that we've already got on
                return -1;
            }
        }
    }
    //lastly if we don't make it to end
    return -1;
}