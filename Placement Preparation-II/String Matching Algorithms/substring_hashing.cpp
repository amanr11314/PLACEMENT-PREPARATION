/**
* we precompute hash for every substring [0,i]
* then for any substring [l,r]:-
* hash(l,r) = (pre[r] - pre[l-1]) * modinv(p^l)
*
* and for modnv(p^l).. we use fermat's little theorem,
* i.e, modinv(a) under m = pow(a,m-2)
* here, we use fast power for computing pow(a,m-2) log(m-2) time complexity
* 
* so, we are able to compute hash of any substring in constant time.
**/
#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int lli;
using namespace std;
lli pre[1001];
lli inv[1001];


lli substringHash(int l,int r) {
	int result = pre[r];
	if(l>0)	result = ( result - pre[l-1] + mod) % mod;
	
	//since divide operation not permitted in modulo..
    //we can multiply with mod inverse of p^l
	result = (result*inv[l]) % mod;
	
	return result;
}

//binary exponentiation for fast power
//iterative method
lli binpow(lli a,lli b) {
    a %= mod;
    lli res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init(string s) {
    //char set size
	lli p = 31;
	lli pp = 1; //31^0
	inv[0] = 1; //inv pp
	pre[0] = (s[0] - 'a' + 1);
		
	for(size_t i=1;i<s.length();++i) {
		char ch = s[i];
		pp = (pp*p) % mod;
		
        //*** IMPORTANT ***//
		//uisng fermat's little theorem for computing mod inverse
		//mod inv(a) = pow(a,m-2) % m
		inv[i] = binpow(pp, mod - 2);
		
		pre[i] = ( pre[i-1] + (ch - 'a' + 1)*pp ) % mod;
	}
}

int main() {
	string s;
	cin>>s;
	
    //precompute hash for strings
	init(s);
	
	int t,l,r;
	cin>>t;
	while(t--) {
		cin>>l>>r;
		cout<<substringHash(l,r)<<'\n';
	}
	
	return 0;
}