//To print all interleavings of two strings.
//a string is called interleaving if it has all characters of two strings and 
//also maintains their order.

void interleaf(string a,string b,string c,int aa,int bb,int i){
    if(aa==0 && bb==0){
        //if no character left in either string print the interleaf
        cout<<c<<endl;
    }
    if(aa!=0){
        //include charcter from first string into interleaf
        c[i]= a[0];
        interleaf(a.substr(1),b,c,aa-1,bb,i+1);
    }
    if(bb!=0){
        //include charcter from second string into interleaf
        c[i] = b[0];
        interleaf(a,b.substr(1),c,aa,bb-1,i+1);
    }
}