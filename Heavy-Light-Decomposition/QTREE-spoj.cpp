// https://www.spoj.com/problems/QTREE/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define LN 14
#define root 0
const int nax = 2e5;
int n , q ;

vector<int> edges[nax] , costs[nax] , indexx[nax];
int chainHead[nax] , chainInd[nax] , chainNo , posInBase[nax];
int depth[nax] , pa[LN][nax] , otherEnd[nax] , subsize[nax];
int baseArray[nax] , ptr;
int st[nax] , qt[nax];

void make_tree(int cur, int s, int e) {
	if(s == e-1) {
		st[cur] = baseArray[s];
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
void query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		qt[cur] = -1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m, e, S, E);
	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v) {
	if(u == v) return 0; // Trivial
	int uchain, vchain = chainInd[v], ans = -1;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v) break;
			query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			// Above is call to segment tree query function
			if(qt[1] > ans) ans = qt[1]; // Update answer
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		if(qt[1] > ans) ans = qt[1];
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ans = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	if(temp > ans) ans = temp; // take the maximum of both paths
	cout<<ans<<"\n";
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */

void HLD(int u , int cost , int p){
	if(chainHead[chainNo] == -1){
		chainHead[chainNo] = u; // Assign chain head
	}
	chainInd[u] = chainNo;
	posInBase[u] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	int sc = -1 , ncost; // Loop to find special child
	int i = 0;
	for(auto x : edges[u]){
		if(x != p){
			if(sc == -1 || subsize[sc] < subsize[x]){
				sc = x;
				ncost = costs[u][i];
			}
		}
		i++;
	}

	if(sc != -1){
		HLD(sc,ncost,u); // Expand the chain
	}
	i = 0;
	for(auto x : edges[u]){
		if(x != p){
			if(sc != x){
				chainNo++;
				HLD(x,costs[u][i],u);
			}
		}
		i++;
	}
}


void dfs(int u , int p , int _d = 0){
	pa[0][u] = p;
	depth[u] = _d;
	subsize[u] = 1;
	int i = 0;
	for(auto x : edges[u]){
		if(x != p){
			otherEnd[indexx[u][i]] = x;
			dfs(x,u,_d+1);
			subsize[u] += subsize[x];
		}
		i++;
	}
}
 
void clear(int k){
	for(int i = 0 ; i < k ; i++){
		edges[i].clear();
		costs[i].clear();
		indexx[i].clear();
		chainHead[i] = -1;
		for(int j = 0 ; j < LN ; j++)
			pa[j][i] = -1;
	}
}

void test(){
	ptr = 0;
	cin >> n;
	clear(n);
	for(int i = 0 ; i < n-1 ; i++){
		int u , v , c;
		cin >> u >> v >> c;
		u-- , v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		costs[u].push_back(c);
		costs[v].push_back(c);
		indexx[u].push_back(i);
		indexx[v].push_back(i);
	}
	chainNo = 0;
	dfs(root,-1); // We set up subsize , depth and parent for each node
	HLD(root,-1,-1); // We decomposed the tree and created baseArray so that segment tree can be setup on that
	make_tree(1,0,ptr);

	for(int i = 1 ; i < LN ; i++){
		for(int j = 0 ; j < n ; j++){
			if(pa[i-1][j] != -1)
				pa[i][j] = pa[i-1][pa[i-1][j]];
		}
	}
	while(true){
		string s;
		cin >> s;
		if(s[0] == 'D')
			break;
		if(s[0] == 'C'){
			int i , ti;
			cin >> i >> ti;
			i--;
			change(i,ti);
		}
		else{
			int a , b;
			cin >> a >> b;
			a-- , b-- ;
			query(a,b);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	cin >> T;
	while(T--){
		test();
	}
}
