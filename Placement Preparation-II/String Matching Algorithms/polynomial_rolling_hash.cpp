/**
* Polynomial rolling hash
* Let length of string is n.
* hash of string is calculated as :-
* hash(s) = i=0..n-1 sum of s[i]*p^i mod m
* where p is prime no.greater than charset size.. 
* where m is very large prime numberfor taking mod
*
* Why need modulo?
* To avoid integer overflow.
* Since, hash function is polynomial, its hash value increases exponentially.
*
* Why p>=charset_size?
* To reduce no. of collisions.
**/

#include<bits/stdc++.h>
#define mod 1000000007;
typedef long long int lli;
using namespace std;

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


int main() {
	string s;
	cin>>s;
	cout<<getHash(s)<<'\n';
	return 0;
}