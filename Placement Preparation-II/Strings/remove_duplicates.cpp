//to remove duplicate charters from string.
void removeDuplicate(string &s){
    int arr[257] = {0};
    string ss="";
    for(int i=0;i<s.length();++i){
        if(
            !arr[s.at(i)]
        )   {
            ss.push_back(s.at(i));
            arr[s.at(i)]++;
        }
    }
    s.assign(ss.c_str());
}