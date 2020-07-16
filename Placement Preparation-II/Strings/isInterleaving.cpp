//recursive approach
bool isInterleaf(string a,string b,string c){
    //if no more chars in a and b return true.. since we've matched all chars
    if(a.size()==0 && b.size()==0){
        return true;
    }
    bool a1 = a.front() == c.front();

    bool a2 = b.front() == c.front();

    return (
        //recurr by matching with first char of a 
        (a1 && isInterleaf(a.substr(1),b,c.substr(1))) ||
        //recurr by matching with first char of b
        (a2 && isInterleaf(a,b.substr(1),c.substr(1)))
    );
}

//DP approach
bool isInterleafDP(string a,string b,string c){
    int M = a.size();
    int N = b.size();
    bool IL[M+1][10];
    if(
        (M + N) != c.size()
    )   return false;
    for(int i=0;i<=M;++i){
        for(int j=0;j<=N;++j){
            
            //Fill true for empty strings
            if(i==0&&j==0)  IL[i][j] = 1;
            //only if a is empty and b is compared
            else if(i==0) {
                IL[i][j] = (
                    (b[j-1]==c[j-1]) && IL[i][j-1]
                );
            }
            //only if b is empty and a is compared
            else if(j==0) {
                IL[i][j] = (
                    (a[i-1]==c[i-1]) && IL[i-1][j]
                );
            }
            //check if c is interleaving of b,a or both
            else {
                IL[i][j] = (
                    (//check if current char of a==current char of c and also that till now is c interleaving a
                        (a[i-1]==c[i+j-1]) && IL[i-1][j]
                    ) ||
                    (//check if current char of b==current char of c and also that till now is c interleaving b
                        (b[j-1]==c[i+j-1]) && IL[i][j-1]
                    )
                );
            }

        }
    }

    return IL[M][N];
}