/**
 * Link: https://acm.timus.ru/problem.aspx?space=1&num=1242
 **/
#include<bits/stdc++.h>
using namespace std;
vector<list<int>> gp(1005);
vector<list<int>> gc(1005);
bool vis[1005];
int n;

void dfsP(int v) {
    //dfs recursively on every ansector of node v
	for(auto it:gp[v]) {
		if(!vis[it]) {
            //mark as visited globally either parent or child...; since we need to visit only once
			vis[it] = 1;
			dfsP(it);
		}
	}
}
void dfsC(int v) {
    //dfs recursively on every child of node v
	for(auto it:gc[v]) {
		if(!vis[it]) {
            //mark as visited globally either parent or child...; since we need to visit only once
			vis[it] = 1;
			dfsC(it);
		}
	}
}

int main() {
	scanf("%d",&n);
	
	while(1) {
		string a;
		cin>>a;
		if(a=="BLOOD")	break;
		string b;
		cin>>b;
		
		int u=atoi(a.c_str());
        int v=atoi(b.c_str());
		//add to parent graph
		gp[u].push_back(v);
        //add to child graph
		gc[v].push_back(u);
	}
	
	for(int i=0;i<1005;++i){
		vis[i] = 0;
	}
	int x;
    //IMP: handling infinite input...
	while(scanf("%d",&x)!=EOF){
        //mark current as visited
		vis[x] = 1;
        //dfs to all ancestors of x node
		dfsP(x);
        //dfs to all children of x node
		dfsC(x);
	}
	
	bool ans = 1;
	for(int i=1;i<=n;++i) {
		ans &= vis[i];
        //if not visited print nodes
		if(!vis[i])	cout<<i<<' ';
        //if last node and every node is visited so far.. print 0
		if(i==n && ans)	cout<<0;
	}
	
	return 0;
}