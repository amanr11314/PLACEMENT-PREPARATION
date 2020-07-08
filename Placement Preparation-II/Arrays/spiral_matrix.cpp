//To print matrix spirally.

int arr[10][10];
void spiral(int n, int m) {
    int top = 0, down = n - 1;
    int left = 0, right = m - 1;

    int dir = 0;
    int i;
    //put required conditon
    while (left <= right && top <= down) {
        switch (dir) {
        case 0:
            //top row leftmost to rightmost column
            for (i = left; i <= right; ++i) {
                cout << arr[top][i] << ' ';
            }
            //increase top, we're done visiting this top row
            top++;
            break;
        case 1:
            //right column topmost row to bottom row
            for (i = top; i <= down; ++i) {
                cout << arr[i][right] << ' ';
            }
            //decrease right, we've visited last column
            right--;
            break;
        case 2:
            //bottom row rightmost column to leftmost column
            for (i = right; i >= left; --i) {
                cout << arr[down][i] << ' ';
            }
            //decrese bottom, we've visited last row
            down--;
            break;
        case 3:
            //left column bottom row to top row
            for (i = down; i >= top; --i) {
                cout << arr[i][left];
            }
            //increase left, we've visited upto this much column from start
            left++;
            break;
        }
        //switch pointer to next required direction
        dir = (dir + 1) % 4;
    }
    cout << '\n';
}