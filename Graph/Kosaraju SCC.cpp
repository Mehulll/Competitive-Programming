#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9+7;
const int nax = 1e5+5;

vector<int> edges[nax] , transpose[nax];
vector<int> SCC; // strongly connected component
vector<int> order;
bool vis[nax];
int n , m;

void dfs(int u){
	vis[u] = 1;
	for(auto x : edges[u]){
		if(!vis[x]){
			dfs(x);
		}
	}
	order.push_back(u);
}

void dfs_trans(int u){
	vis[u] = 1;
	for(auto x : transpose[u]){
		if(!vis[x]){
			dfs_trans(x);
		}
	}
	SCC.push_back(u);
}

int cases = 0;
void test_case() {
	cin >> n >> m;
	for(int i = 0 ; i <= n ; i++){
		edges[i].clear();
		vis[i] = 0;
	}
	for(int i = 0 ; i < m ; i++){
		int a , b;
		cin >> a >> b;
		a-- , b--;
		edges[a].push_back(b);
		transpose[b].push_back(a);
	}

	for(int i = 0 ; i < n ; i++){
		if(!vis[i])
			dfs(i);
	}
	for(int i = 0 ; i < n ; i++){
		vis[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(!vis[order[n-1-i]]){
			SCC.clear();
			dfs_trans(order[n-i-1]);
			for(auto x : SCC){
				cout<<x+1<<" ";
			}
			cout<<"\n";
		}
	}

}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(10);
	int T = 1;
	// cin >> T;
	while(T--){
		cases++;
		test_case();
	}
}
