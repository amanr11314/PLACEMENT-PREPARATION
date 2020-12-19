/**
* Problem:- 
* Given two strings :  text and pattern
* find whether pattern exists in text or not.
* If yes, print all occuences of pattern.
* 
* Input:-
* text="cabbage uses cab"
* pattern="cab"
* 
* Output:-
* 0, 13
* 
* Time Complexity:-
* Since we match text with each window of size of pattern :
* len(text) = n
* len(pattern) = m
* total windows to match = n-m+1
* for 1 window = m
* so, for matching (n-m+1) windows = m*(n-m+1)
*                                  = n*m-m^2+m
* for very large n, we can neglect m => O(n*m) overall complexity
**/
#include<bits/stdc++.h>
using namespace std;

//match each window in text from beg, with pattern
bool match(int beg,const string &text,const string &pattern) {
	for(size_t i=0;i<pattern.length();++i) {
		//if any mismatch founud return false
		if(text[beg+i] != pattern[i])	return 0;
	}
	return 1;
} 

int main() {
	
	int t;
	cin>>t;
	string text,pattern;
	cin.ignore();
	while(t--) {
		
		getline(cin,text);
		getline(cin,pattern);
		
		//match for each window in text
		for(size_t i=0;i<(text.length()-pattern.length()+1);++i) {
			if(match(i,text,pattern))	cout<<i<<", ";
		}
		
		puts("");
		
	}
	
}