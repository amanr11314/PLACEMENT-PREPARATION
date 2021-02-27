/**
 *  Link: https://codeforces.com/problemset/problem/580/C 
 **/
#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> tree;
vector<bool> vis;
vector<int> cat;
int ans,m;
void dfs(int v,bool isLeaf,int curr_cats) {
	vis[v] = true;
	if(curr_cats>m)	return;
	if(isLeaf)	{
		//cout<<"leaf node visited "<<v<<endl;
		ans++;
		return;
	}
	
	
    for (int u : tree[v]) {
		
        if (!vis[u]) {
            //if cat at this node incerase by 1 else simply reset to 0
			int cc = (cat[u]) ? (curr_cats+1) : cat[u];
            //leaf if it has 1 child and that too is visited previously.
            //here leaf has 1 child since we're storing undirected graph two ways..
            dfs(u,(tree[u].size()==1 && vis[tree[u][0]]),cc);
		}
    }
}
int main() {
	
	int n;
	cin>>n>>m;
	vis.resize(n+1);
	cat.resize(n+1);
	
	for (int i = 1; i <= n; i++){
		cin>>cat[i];
		tree[i].resize(0);
	}
	
	int u,v;
	for (int i = 1; i < n; i++) {
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	fill(vis.begin(), vis.end(), false);
	ans = 0;
	dfs(1,false,cat[1]);
	cout<<ans;
	return 0;
}