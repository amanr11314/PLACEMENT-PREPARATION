/**
* Link to problem: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/search-me/
* Pattern: " to the " 
* Task: To check whether this substring is present in the input string or not. 
* If present print "YES" otherwise print "NO".
**/
#include<bits/stdc++.h>
using namespace std;

bool match(int beg,const string &text,const string &pattern) {

    //edge case: leading character must be whitespace if not first word
    if(beg != 0)    if(text[beg-1] != ' ')    return 0;

	for(size_t i=0;i<pattern.length();++i) {
		if(text[beg+i] != pattern[i])	return 0;
	}
    //edge case: trailing character must be whitespace if not last word
    if(
        (beg+pattern.length()) < text.length()
    )   if(text[beg+pattern.length()] != ' ')   return 0;
	return 1;
} 

void solve(const string &text,const string &pattern) {
//match for each window in text
    for(size_t i=0;i<(text.length()-pattern.length()+1);++i) {
        if(
            match(i,text,pattern)
        )	{
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}

int main() {
	string text;
    const string pattern = "to the";
	
    getline(cin,text);

    solve(text,pattern);
	return 0;
}