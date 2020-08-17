#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[],int s,int e) {
	
	if(s>=e)	return;
	
	int mid = s + (e - s) / 2;
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);
	
	//merging ...
		int len = e-s+1;
		int *B = new int[len];
		merge(arr+s,(arr+mid+1),(arr+mid+1),(arr+e+1),B);
		for(int i=0;i<len;++i){
			arr[s+i] = B[i];
		}
		
	///UNCOMMENT FOR VISUALIZATION:-
	//cout<<"--MERGED--\n";
	//for(int i=s;i<=e;++i){
		//cout<<arr[i]<<' ';
	//}
	//cout<<'\n';
}

int main(){
	
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;++i)
		cin>>A[i];
	
	merge_sort(A,0,n-1);
	cout<<"----ARRAY AFTER SORTING----\n";
	for(int i:A){
		cout<<i<<' ';
	}
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}



