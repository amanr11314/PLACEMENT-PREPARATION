//to find row with maximum one's in row wise sorted array.

//here we represent 1-D array as 2-D linear array.
int findRow(int arr[], int n, int m)
{
    int c = 0;
    int s = (n * m) + 1;
    int mc = 0;
    int ans = 0;
    for (int i = 1; i < s; ++i)
    {
        //we kepp count of 1's in each row
        if (arr[i] == 1)
            c++;
        
        //check if we reached end of a row
        if (i % m == 0)
        {
            //if new max 1's found
            if (c > mc)
            {
                mc = c;
                //ans as 1 based index of row with maximum no. of 1's
                ans = i / m;
            }
            //set count to 0 once a row has finished.
            c = 0;
        }
    }
    //return 0 based index of row with maximum 1's
    return(ans - 1);
}