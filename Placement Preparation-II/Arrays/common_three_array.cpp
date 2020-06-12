// Find common elements in three sorted arrays
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long int lll;
bool compare(vector<lll> a,vector<lll> b){
	return a.size()<b.size();
}


int main(){

    ll n1,n2,n3;
	cin>>n1>>n2>>n3;
	lll temp;
	vector< vector<lll> > arrs(3);
    
    //taking input
	for(int i=0;i<n1;++i){
		cin>>temp;
		arrs[0].push_back(temp);
	}
	for(int i=0;i<n2;++i){
		cin>>temp;
		arrs[1].push_back(temp);
	}
	for(int i=0;i<n3;++i){
		cin>>temp;
		arrs[2].push_back(temp);
	}
	
    //sort 3 arrays by their size
	sort(arrs.begin(),arrs.end(),compare);

	set<lll> d;
	set<lll> d2;

    //find and insert common elements b/w arr0,arr1 into set d.
	for(int i=0;i<arrs[0].size();++i){
		if (binary_search(arrs[1].begin(),arrs[1].end(),arrs[0].at(i)))
			d.insert(arrs[0].at(i)); 
	}

	set<lll>::iterator it;
    //finally iterate through set d
    //to find elements common b/w set d and arr2  into set d2
	for (it = d.begin(); it != d.end(); ++it) {
		if (binary_search(arrs[2].begin(), arrs[2].end() , *it))
			d2.insert(*it);
	}

    //if d2 is not empty print coomon elements between 3 arrays
	if(d2.size())
	for (it = d2.begin(); it != d2.end(); ++it) {
		cout<<*it<<' ';
	}
	else
	cout<<-1;
    

    return 0;
}
