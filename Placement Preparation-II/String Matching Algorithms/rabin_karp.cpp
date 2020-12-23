/**
* * * * * * * * * * * * * * * * * * * * * * * * RABIN KARP ALGORITHM * * * * * * * * * * * * * * * * * * * * * * * * 
*
* Write a program that finds all occurences of a given pattern in a given input string.
* This is often referred to as finding a needle in a haystack.
*
* The program has to detect all occurences of the needle in the haystack. 
* It should take the needle and the haystack as input, 
* and output the positions of each occurence, as shown below.
* Link to the problem:- https://www.spoj.com/problems/NHAY/
* 
* Modified substrig hashing:-
* we precompute hash for every substring [0,i]
* then for any substring [l,r]:-
* As per equation:- 
* hash(l,r) = (pre[r] - pre[l-1]) / p^l
* now instead of calculating modular inverse, we send p^l to LHS
* this becomes constant time operation since we can calculate p^l in constant time while precomputing hash
* now, we only have to compare:-
* hash(pattern)*p^l == substringHash(l,r)
* complexity: O(n+m) modified algorithm
* 
* Note:-
* while computing hash(pattern)*p^l take care of large values so to take mod here too...
**/
#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int lli;
using namespace std;
lli pre[1000001];
lli inv[1000001];
lli pL[1000001];

lli substringHash(int l,int r) {
	lli result = pre[r];
	if(l>0)	result = ( result - pre[l-1] + mod) % mod;
	return result;
}

void init(string s) {
	lli p = 31;
	lli pp = 1; //31^0
	inv[0] = 1; //inv pp
	pre[0] = (s[0] - 'a' + 1);
	pL[0] = 1;
		
	for(size_t i=1;i<s.length();++i) {
		char ch = s[i];
		pp = (pp*p) % mod;
		
		pL[i] = (pL[i-1] * p) % mod;
		
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
	lli val1,val2;
	for(size_t i=0,r=l-1;r<b.length();++i,r++) {
        //computing hash*p^L % mod effectively..
		val1 = (aHash%mod)*(pL[i]%mod);
		if(val1>mod)	val1 %= mod;
		if(val1<0)	val1 += mod;

		val2 = substringHash(i,r);
		
		if(
			val1==val2
		) 
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


