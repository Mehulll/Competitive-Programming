// https://codeforces.com/contest/1006/problem/E
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

const int nax = 2e5+5;
vector<int> edges[nax];
int s[nax];
int e[nax];
int dt;
int ist[nax];

void dfs(int u){
	ist[s[u] = dt++] = u;
	for(auto v : edges[u])
		dfs(v);
	e[u] = dt;
}

void test_case() {
	int n , q;
	cin >> n >> q;
	for(int i = 1 ; i < n ; i++){
		int x;
		cin >> x;
		x--;
		edges[x].push_back(i);
	}
	for(int i = 0 ; i < n ; i++)
		sort(edges[i].begin(),edges[i].end());
	dfs(0);
	while(q--){
		int u , k;
		cin >> u >> k;
		u-- , k-- ;
		cout << (k >= e[u] - s[u] ? -1 : ist[s[u]+k]+1) <<"\n";
	}
}
 
int main() {
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
