// to fill an area of matrix and its surroundings having particular number with given number
/*

Given:
   0 1 2 3 4 5 6
0| 1 1 1 2 1 1 1
1| 2 2 1 2 2 1 1
2| 0 2 2 2 1 1 1
3| 1 1 0 2 1 2 2
4| 1 1 2 2 1 0 0

To flood fill (3,3) with 9 would look like

   0 1 2 3 4 5 6
0| 1 1 1 9 1 1 1
1| 9 9 1 9 9 1 1
2| 0 9 9 9 1 1 1
3| 1 1 0 9 1 2 2
4| 1 1 9 9 1 0 0


*/
void floodFill(int arr[8][8], int m, int n, int r, int c, int toFill, int prevFill) {

    //check if putside matrix
    if (r < 0 || r >= m || c < 0 || c >= n){
        return;
    }
    //check if not equal to previous number we want to flood fill and replace
    if (arr[r][c] != prevFill){
        return;
    }
    //fill the grid
    arr[r][c] = toFill;

    //up
    floodFill(arr, m, n, r - 1, c, toFill, prevFill);

    //down
    floodFill(arr, m, n, r + 1, c, toFill, prevFill);

    //left
    floodFill(arr, m, n, r, c - 1, toFill, prevFill);

    //right
    floodFill(arr, m, n, r, c + 1, toFill, prevFill);
}