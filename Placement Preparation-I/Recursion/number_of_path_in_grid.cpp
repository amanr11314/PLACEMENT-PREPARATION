//to find number of paths from (1,1)->(n,m) in a n*m grid
int path(int n, int m){
    if (n == 1 || m == 1)
        return 1;
    return path(n, m - 1) + path(m, n - 1);
}