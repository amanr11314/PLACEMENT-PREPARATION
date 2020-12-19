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