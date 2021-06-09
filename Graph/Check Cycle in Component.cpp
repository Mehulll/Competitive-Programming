/*
https://atcoder.jp/contests/arc114/tasks/arc114_b
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using ll = long long;
#define ar array 
clock_t time_req = clock()*1.0/CLOCKS_PER_SEC;

#define int ll
const int nax = 2e5+5;
const int NAX = 505;
const int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};
int ans = 0;
bool seen[NAX][NAX];
int grap[NAX][NAX];
vector<int> edges[nax];
int vis[nax] , vis2[nax];
int vertex[nax];
// int s[nax];
int e[nax];
int dt;
int ist[nax];
int degree[nax];
int n , m , k , s, t;
vector<pair<int,int>> child[nax];
int maxDist[nax];
pair<int,int> parent[nax];
vector<pair<int,int>> comp;
int subSize[nax];
int p;
bool check[nax];

int dfs(int u){
	if(u == p)
		check[u] = true;
	else
		check[u] = false;
	vis[u] = 1;
	int cur_s = 1;
	for(auto x : edges[u]){
		if(!vis[x]){
			cur_s += dfs(x);
			check[u] |= check[x];
		}
	}
	return subSize[u] += cur_s;
}

// bool cycle(int node , int par){
// 	vis2[node] = 1;
// 	for(int child : edges[node]){
// 		if(vis2[child] == 0){
// 			if(cycle(child,node) == true)
// 				return true;
// 		}
// 		else
// 			if(child != par)
// 				return true;
// 	}
// 	return false;
// }

// bool valid(int i , int j){
// 	return (i >= 0 && j >= 0 && i < n && j < m && grap[i][j] == 1 && seen[i][j] == 0);
// }

// void dfs(int x , int y){
// 	seen[x][y] = 1;
// 	all[ans].push_back({x,y});
// 	for(int i = 0 ; i < 4 ; i++){
// 		if(valid(x+dx[i],y+dy[i])){
// 			dfs(x+dx[i],y+dy[i]);
// 		}
// 	}
// }

void rem(int node){
	vis[node] = 0;
	for(auto x : child[node])
		rem(x.first);
}

void dp(int node , int par){
	maxDist[node] = max(0ll,maxDist[par] + parent[node].second);
	if(maxDist[node] > vertex[node])
		rem(node);
	else
		for(auto x : child[node])
			dp(x.first,node);
}

void finish(){
	ans = 0;
	for(int i = 1 ; i <= n ; i++)
		if(vis[i])
			ans++;
	cout<<(n-ans)<<"\n";
}
// ll gcd(ll x, ll y)
// {
// 	return (y == 0 ? x : gcd(y, x % y));
// }
// ll lcm(ll x, ll y)
// {
// 	return (x / gcd(x, y)) * y;
// }

int dist[nax];
// int a[nax];
void bfs(int src){
	vis[src] = 1;
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto x : edges[u]){
			if(!vis[x]){
				q.push(x);
				vis[x] = 1;
				dist[x] = dist[u] + 1;
			}
		}
	}
}

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

void test_case() {
	ans = 1;
 	cin >> n;
    vector<int> a(n); 
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++){
      a[i]--;
    }
    for(int i = 0 ; i < n ; i++){
    	if(vis[i])
    		continue;
    	int x = i;
    	while(vis[x] == 0){
    		vis[x] = 1;
    		x = a[x];
    	}
    	if(vis[x] == 1)
    		ans = add(ans,ans);
    	x = i;
    	while(vis[x] == 1){
    		vis[x] = 2;
    		x = a[x];
    	}
    }
    ans = sub(ans,1);
    cout<<ans<<"\n";
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(10);
	int T = 1;
	// cin >> T;
	while(T--){
		test_case();
	}
}

// dont take stress
// remember the i , j index in double loop
// typing slow but dont make mistake while thinking and typing
 
 // 4 4 8 2 2 2 2 2 4 4 1 1 1 1 1 1 1 1 2 2 2 2
