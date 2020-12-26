/**
 * Link to problem:     https://codeforces.com/contest/271/problem/D
 * 
 * You've got string s, consisting of small English letters. 
 * Some of the English letters are good, the rest are bad.
 * A substring s[l...r] (1 ≤ l ≤ r ≤ |s|) of string s  =  s1s2...s|s| (where |s| is the length of string s) is string  slsl + 1...sr.
 * The substring s[l...r] is good, if among the letters  sl, sl + 1, ..., sr 
 * there are at most k bad ones (look at the sample's explanation to understand it more clear).
 * Your task is to find the number of distinct good substrings of the given string s. Two substrings s[x...y] and s[p...q] are considered distinct if their content is different, i.e. s[x...y] ≠ s[p...q].
 * 
 * Input
 * The first line of the input is the non-empty string s, consisting of small English letters, the string's length is at most 1500 characters.
 * The second line of the input is the string of characters "0" and "1", the length is exactly 26 characters.
 *  If the i-th character of this string equals "1", then the i-th English letter is good, otherwise it's bad. 
 * That is, the first character of this string corresponds to letter "a", the second one corresponds to letter "b" and so on.
 * The third line of the input consists a single integer k (0 ≤ k ≤ |s|) — the maximum acceptable number of bad characters in a good substring. 
 * 
 * Output 
 * Print a single integer — the number of distinct good substrings of string s.
 * 
 * Solution:
 * Managed to get AC using good memory maanagement i.e using hashset for strings of same length only at a time..
 * However Hashing gives collision at some time...
 * Better approach is to use trie and suffix array..
 **/
#include<bits/stdc++.h>
using namespace std;
 
string s;
string alpha;
int k;
int *pre;
//find number of substring with hash sum <= k
//hash sum = no. of badness of substring
void init() {
	pre = new int[s.length()];
	
	pre[0] = (alpha[s[0]-'a']=='0');
	
	for(size_t i=1;i<s.length();++i) {
		pre[i] = pre[i-1] + (alpha[s[i]-'a']=='0');
	}
}
int badness(int l,int r) {
	int result = pre[r];
	
	if(l>0)	result = (result - pre[l-1]);
	return result;
}
int main() {
	
	cin>>s;
	cin>>alpha;
	cin>>k;
	
	init();
	
	int n = (int)s.size();
	
	string tt;
	int r,val;
	int ans=0;
	
	for (int len = 1; len <= n; len++) {
		
		//good memory management
		//hash only same length substrings to avoid memory limit.. xD
		unordered_set<string> us;
	
        for (int i = 0; i < n-len+1; i++) {
			tt = s.substr(i, len);
			r = i+len-1;
			if(r>=i && r<n) {
				val = badness(i,r);
				if(val<=k)	{
					us.insert(tt);	
					//cout<<"\tYes";
				}
				//puts("");
			}
		}
		ans+=us.size();
	}
	cout<<ans;
	return 0;
}
