//store all unique permuatations of string as key in hashmap mp
unordered_map<string, int> mp;
void permuteString(string s, int l, int r){
    if (l == r){
        //new permutation found
        if (!mp[s]){
            mp[s] = 1;
            cout << s << '\n';
        }
        return;
    }
    for (int i = l; i <= r; ++i){
        
        swap(s[l], s[i]);
        
        //to generate next permutation from l to i
        permuteString(s, l + 1, r);

        swap(s[l], s[i]);
    }
}