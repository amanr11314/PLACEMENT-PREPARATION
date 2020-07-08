//To find median element in matrix whose each row is sorted.
//It is assured that total element count in matrix is odd.
#define MAX 100001
int medianElement(int arr[MAX][MAX], int n, int m){
    /*
    Let's say array is of form:
        [min0 ...... max0]
        [min1 ...... max1]
        [min2 ...... max2]
    Then median element will be some number b/w :
        min(min0,min1,min2) and max(max0,max1,max2)

        ---------------------------------------------------------------------
       | When counter is less than expected then range becomes [ mid,max ]   |
       | When counter is more than expected then range becomes [ min,mid ]   |
        ---------------------------------------------------------------------

    Now There are three cases possible:-
    1.) Median can be actual mid element.
        i.e median = (low + high)/2
        In this case there are exactly (n*m)/2 elements less than 
        or equal to median.

        e.g. [1,2,3]
             [4,5,6]
             [7,8,9]

        Here,
            min = 1     max = 9
            median_expected = (1+9)/2 => 5
            n_less_than_median = 3+1+0 => 5
            n_less_than_median == (n*m+1)/2 => 5
            
            5 > (n*m+1)/2 => 5>5 becomes false

            So, median lies b/w 1 and 5

            min = 1     max = 5
            median_expected = (1+5)/2 => 3
            n_less_than_median = 3+0+0 => 3
            n_less_than_median == (n*m+1)/2 => 5
            3 < (n*m+1)/2 => 3<5

            So, median lies between 4 and 5

            min = 4     max = 5
            median_expected = (4+5)/2 => 4
            n_less_than_median = 3+1+0 => 4
            n_less_than_median == (n*m+1)/2 => 5
            4 < (n*m+1)/2 => 4<5

            So, median lies between 5 and 5

            min = 5
            max = 5
            since (min<max), condition becomes false,
            Median element is 5

    
    2.) Median can be element less than expected median.
        e.g. [1,2,3]
             [3,3,5]
             [7,8,9]
        Here,
            min = 1     max = 9
            median_expected = (1+9)/2 => 5
            n_less_than_median = 3+3+0 => 6
            6 > (n*m+1)/2 => 6>5

            So, median lies b/w 1 and 5

            min = 1     max = 5
            median_expected = (1+5)/2 => 3
            n_less_than_median = 3+2+0 => 5
            5 > (n*m+1)/2 => 5>5 becomes false

            So,median lies b/w 1 and 3

            min = 1     max = 3
            median_expected = (1+3)/2 => 2
            n_less_than_median = 2+0+0 => 2
            2 < (n*m)/2 => 2<4

            So, median lies b/w 3 and 3

            min = 3
            max = 3
            since (min<max), condition becomes false,
            Median element is 3





    
    3.) Median can be element greater than expected median.
        e.g. [1,2,3]
             [5,6,6]
             [7,8,9]
        Here,
            min = 1     max = 9
            median_expected = (1+9)/2 => 5
            n_less_than_median = 3+1+0 => 4
            4 < (n*m+1)/2 => 4<5

            So, median lies b/w 6 and 9

            min = 6     max = 9
            median_expected = (6+9)/2 => 7
            n_less_than_median = 3+3+1 => 7
            7 > (n*m+1)/2 => 7>5

            So,median lies b/w 6 and 7

            min = 6     max = 7
            median_expected = (6+7)/2 => 6
            n_less_than_median = 3+3+0 => 6
            6 > (n*m+1)/2 => 6>5

            So, median lies b/w 6 and 6

            min = 6
            max = 6
            since (min<max), condition becomes false,
            Median element is 6
    */

    int low = arr[0][0], high = arr[0][m - 1];

    for (int i = 1; i < n; ++i) {
        low = min(low, arr[i][0]);
        high = max(high, arr[i][m - 1]);
    }

    int desired_count = (n * m + 1) / 2;

    int mid = (low + high) / 2;

    int counter = 0;
    while (low < high) {
        counter = 0;
        int mid = (high + low) / 2;

        for (int i = 0; i < n; i++)
            counter += upper_bound(arr[i], arr[i] + m, mid) - arr[i];

        if (counter < desired_count)
            low = mid + 1;
        else
            high = mid;
        cout << "- - - - - - -\n";
    }
    return low;
}