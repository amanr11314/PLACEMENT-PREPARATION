//To efficiently compute nPr:-
/**
 * nPr is calculated by using relation :--
 * nPr = (n-1)P(r) + r * (n-1)P(r-1)
 * _______________________________________
 * Another best approach is to notice that:--
 * P(10,2) = 10 * 9
 * P(10,3) = 10 * 9 * 8
 * i..e P(n,r) = n * (n-1) ..*(n-r+1)
 * */

#include<bits/stdc++.h> 
using namespace std; 
  
// O(n*k) time and space complecity
int solve(int n, int k)  { 
    int P[n + 1][k + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= std::min(i, k); j++) { 
            if (j == 0) 
                P[i][j] = 1; 
  
            else
                P[i][j] = P[i - 1][j] +  (j * P[i - 1][j - 1]); 

            //for j>i
            P[i][j + 1] = 0; 
        } 
    } 
    return P[n][k]; 
} 

//O(n) apporach
int solve(int n,int k) {
    if(k==0 || k==n)	return 1;
    int npk = 1;
    for(int i=n;i>=n-k+1;--i) {
        npk*=i;
    }
    return npk;
}