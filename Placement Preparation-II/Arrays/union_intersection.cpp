//to print union and intersection of two sorted arrays

void printUnion(int a[],int b[],int n,int m){
    unordered_set<int> table;
    cout<<a[0]<<' ';
    //store first element in table too
    table.insert(a[0]);
    for(int i=1;i<n;++i){
        //handling duplicates
        if(a[i]!=a[i-1]){
            cout<<a[i]<<' ';
            //store element in table
            table.insert(a[i]);
        }
    }
    for(int j=0;j<m;++j){
        //if not in table
        if(table.find(b[j])==table.end()){
            cout<<b[j]<<' ';
            //store  element in table
            table.insert(b[j]);
        }
    }
}

void printIntersection(int a[],int b[],int n,int m){
    unordered_set<int> table;
    for(int i=0;i<n;++i){
        table.insert(a[i]);
    }
    if(table.find(b[0])!=table.end()){
        cout<<b[0]<<' ';
    }
    for(int i=1;i<m;++i){
        if(b[i]!=b[i-1]){
             if(table.find(b[i])!=table.end()){
                cout<<b[i]<<' ';
            }
        }
    }

}