//To print all sub-sequences of a string.

/*

    a
    	ab
    		abc
    	ac
    b
    	bc
    c
    ------------------------------
    
    a
    	ab
		    abc
    			abcd
    		abd
    	ac
    		acd
    	ad
    b
    	bc
    		bcd
    	bd
    c
    	cd
    d
*/
//for lexicographical order:- store subsequences into multiset
void printSubsequence(string s,int index=0,string t="") {
    cout<<t<<'\n';
    
    for(int i=index;i<s.length();++i) {
        // including s[i] in subsequence
        //only print when s[i] added in subsequence
        t.push_back(s[i]);  
        printSubsequence(s,i+1,t);
        // not including s[i] in subsequence    
        t.pop_back();
    }
}