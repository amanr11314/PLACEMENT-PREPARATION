// Prints elements with more than n/k occurrences in arr[] of 
// size n. If there are no such elements, then it prints nothing. 

//this is modification of Booye Moore's voting algorithm..

/*
    There can be maximum (k-1) elements that occur more than (n/k) times.
    Proof:-

    let:
        n = size of array
        k = given
        v = |_ (n/k) _| i.e frequency
        then..
        ___________
       |           |
       |  v*k = n  | ...(i)
       |___________|
       i.e there are maximum k elements with frequency |_ n/k _|

       since we want elements with frequency more than |_ n/k _|,
       
    let: 
        v' be frequency more than v.
        and let a elements in array occur with frequency v' such that :
        ___________
       |           |
       |  v'*a = n |
       |___________|

       since v'>v,
       then for balancing equation (i) 
                    a<k

        since a<k...
         max(a) = (k-1) only...

        So, there are atmost (k-1) distinct elements with frequency more than
        |_ n/k _|

*/

//so here unlinke MAJORITY ELEMENT, we've (k-1) elements so we create a struct type
//to hold an element and make array of it of size (k-1)

struct eleCount { 
    int e;  // Element 
    int c;  // Count 
    eleCount(){
        this->c = 0;
        this->e = 0;
    }
    eleCount(const eleCount &obj){
        this->e = 0;
        this->c = 0;
    }
}; 

// Prints elements with more than n/k occurrences in arr[] of 
// size n. If there are no such elements, then it prints nothing. 
void moreThanNdK(int arr[], int n, int k) { 
    // k must be greater than 1 to get some output 
    if (k < 2) 
       return; 
  
    /* Step 1: Create a temporary array (contains element 
       and count) of size k-1. Initialize count of all 
       elements as 0 */

    struct eleCount temp[k-1]; 

    for (int i=0; i<k-1; i++) 
        temp[i].c = 0; 

    /* Step 2: Process all elements of input array */
    for (int i = 0; i < n; i++) { 
        int j; 

        ///CASE-I

        /* If arr[i] is already present in 
           the element count array, then increment its count */
        for (j=0; j<k-1; j++) { 
            if (temp[j].e == arr[i]) { 
                 temp[j].c += 1; 
                 break; 
            } 
        } 

        ///CASE-II

        /* If arr[i] is not present in temp[] */
        if (j == k-1) { 
            int l; 
            
            ///CASE-II (a):

            /* If there is position available in temp[], then place  
              arr[i] in the first available position and set count as 1*/
            for (l=0; l<k-1; l++) { 
                if (temp[l].c == 0) { 
                    temp[l].e = arr[i]; 
                    temp[l].c = 1; 
                    break; 
                } 
            } 
            
            ///CASE-II (b):
            
            /* If all the position in the temp[] are filled, then  
               decrease count of every element by 1 */
            if (l == k-1) 
                for (l=0; l<k; l++) 
                    temp[l].c -= 1; 
        } 
    }

    /*Step 3: Check actual counts of potential candidates in temp[]*/
    for (int i=0; i<k-1; i++) { 
        // Calculate actual count of elements  
        int ac = 0;  // actual count 
        for (int j=0; j<n; j++) 
            if (arr[j] == temp[i].e) 
                ac++; 
  
        // If actual count is more than n/k, then print it 
        if (ac > n/k) 
           cout << "Number:" << temp[i].e 
                << " Count:" << ac << endl; 
    } 
} 