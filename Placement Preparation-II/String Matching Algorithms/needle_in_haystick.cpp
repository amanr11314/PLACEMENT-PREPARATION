/**
* Write a program that finds all occurences of a given pattern in a given input string.
* This is often referred to as finding a needle in a haystack.
*
* The program has to detect all occurences of the needle in the haystack. 
* It should take the needle and the haystack as input, 
* and output the positions of each occurence, as shown below.
* Link to the problem:- https://www.spoj.com/problems/NHAY/
**/
#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int lli;
using namespace std;
lli pre[1000001];
lli inv[1000001];

lli substringHash(int l,int r) {
	int result = pre[r];
	if(l>0)	result = ( result - pre[l-1] + mod) % mod;
	
	
	result = (result*inv[l]) % mod;
	
	return result;
}

lli binpow(lli a,lli b) {
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
	lli p = 31;
	lli pp = 1; //31^0
	inv[0] = 1; //inv pp
	pre[0] = (s[0] - 'a' + 1);
		
	for(size_t i=1;i<s.length();++i) {
		char ch = s[i];
		pp = (pp*p) % mod;
		
		//uisng fermat's little theorem for computing mod inverse
		//mod inv(a) = pow(a,m-2) % m
		inv[i] = binpow(pp, mod - 2);
		
		pre[i] = ( pre[i-1] + (ch - 'a' + 1)*pp ) % mod;
	}
}

lli getHash(string key) {
	lli value = 0;
	lli p = 31;
	lli pp = 1; //p^0 = 1 further multipy with p
	for(char ch:key) {
		value = (value + (ch-'a'+1)*pp) % mod;
		pp = (pp*p) % mod;
	}
	return value;
}

void solve(int l,string a,string b) {
	
	init(b);
	lli aHash = getHash(a);
	for(size_t i=0;i<(b.length()-l+1);++i) {
		if(aHash==substringHash(i,i+l-1)) 
			cout<<i<<'\n';
	}
	puts("");
}

int main() { 
	int l;
	string a,b;
	while(cin>>l){
		cin>>a;
		cin>>b;
		solve(l,a,b);
		
	}
	
	return 0;
}
