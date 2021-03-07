/*
https://codeforces.com/problemset/problem/1133/F1

bhale dinoñ kī baat hai 

bhalī sī ek shakl thī 

na ye ki husn-e-tām ho 

na dekhne meñ aam sī 

na ye ki vo chale to kahkashāñ sī rahguzar lage 

magar vo saath ho to phir bhalā bhalā safar lage 

koī bhī rut ho us kī chhab 

fazā kā rañg-rūp thī 

vo garmiyoñ kī chhāñv thī 

vo sardiyoñ kī dhuup thī 

na muddatoñ judā rahe 

na saath sub.h-o-shām ho 

na rishta-e-vafā pe zid 

na ye ki izn-e-ām ho 

na aisī ḳhush-libāsiyāñ 

ki sādgī gila kare 

na itnī be-takallufī 

ki aa.ina hayā kare 

na iḳhtilāt meñ vo ram 

ki bad-maza hoñ ḳhvāhisheñ 

na is qadar supurdagī 

ki zach kareñ navāzisheñ 

na āshiqī junūn kī 

ki zindagī azaab ho 

na is qadar kaThor-pan 

ki dostī ḳharāb ho 

kabhī to baat bhī ḳhafī 

kabhī sukūt bhī suḳhan 

kabhī to kisht-e-za.afarāñ 

kabhī udāsiyoñ kā ban 

sunā hai ek umr hai 

muāmalāt-e-dil kī bhī 

visāl-e-jāñ-fazā,n to kyā 

firāq-e-jāñgusil kī bhī 

so ek roz kyā huā 

vafā pe bahs chhiḌ ga.ī 

maiñ ishq ko amar kahūñ 

vo merī zid se chiḌ ga.ī 

maiñ ishq kā asiir thā 

vo ishq ko qafas kahe 

ki umr bhar ke saath ko 

vo bad-tar-az-havas kahe 

shajar hajar nahīñ ki ham 

hamesha pā-ba-gil raheñ 

na Dhor haiñ ki rassiyāñ 

gale meñ mustaqil raheñ 

mohabbatoñ kī vus.ateñ 

hamāre dast-o-pā meñ haiñ 

bas ek dar se nisbateñ 

sagān-e-bā-vafā meñ haiñ 

maiñ koī panting nahīñ 

ki ik frame meñ rahūñ 

vahī jo man kā miit ho 

usī ke prem meñ rahūñ 

tumhārī soch jo bhī ho 

maiñ us mizāj kī nahīñ 

mujhe vafā se bair hai 

ye baat aaj kī nahīñ 

na us ko mujh pe maan thā 

na mujh ko us pe zo.am hī 

jo ahd hī koī na ho 

to kyā ġham-e-shikastagī 

so apnā apnā rāsta 

hañsī-ḳhushī badal diyā 

vo apnī raah chal paḌī 

maiñ apnī raah chal diyā 

bhalī sī ek shakl thī 

bhalī sī us kī dostī 

ab us kī yaad raat din 

nahīñ, magar kabhī kabhī 
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
const int NAX = 55;
const int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};
int ans = 0;
bool seen[NAX][NAX];
int grap[NAX][NAX];
vector<int> edges[nax];
bool vis[nax] , vis2[nax];
int vertex[nax];
int s[nax];
int e[nax];
int dt;
int ist[nax];
int degree[nax];
int n , m , k;
vector<pair<int,int>> child[nax];
int maxDist[nax];
pair<int,int> parent[nax];
vector<pair<int,int>> comp;

void dfs(int u){
	vis[u] = 1;
	for(auto x : edges[u])
		if(!vis[x]){
			dfs(x);
		}
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



void bfs(int src){
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int x : edges[node]){
			if(!vis[x]){
				q.push(x);
				vis[x] = 1;
				cout<<node+1<<" "<<x+1<<"\n";
			}
		}
	}
}

void test_case() {
 cin >> n >> m;
 for(int i = 0 ; i < m ; i++){
 	int a , b;
 	cin >> a >> b;
 	a-- , b--;
 	edges[a].push_back(b);
 	edges[b].push_back(a);
 }
 int maxDegree = 0;
 int maxNode = -1;
 for(int i = 0 ; i < n ; i++){
 	if((int)edges[i].size() > maxDegree){
 		maxDegree = edges[i].size();
 		maxNode = i;
 	}
 }
 bfs(maxNode);
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
