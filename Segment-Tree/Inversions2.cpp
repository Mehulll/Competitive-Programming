// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
#include <bits/stdc++.h>
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

const int INF = 1e9+5;
typedef int item;
 
struct segtree {
	
	int size;
	vector<item> values;
	
	item NEUTRAL = 0;
	
	item merge(item a , item b){
		return a+b;
	}
	
	item single(int v){
		return v;
	}
	
	void init(int n){
		size = 1;
		while(size < n)
			size*=2;
		values.resize(2*size,1LL);
	}
	
	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				values[x] = single(a[lx]);
			}
			return;
		}
		
		int m = (lx + rx)/2;
		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		values[x] = merge(values[2*x+1],values[2*x+2]);
	}
	
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	
	void set(int i , int v , int x , int lx , int rx){
		if(rx-lx==1){
			values[x] = single(v);
			return;
		}
		int m = (rx+lx)/2;
		if(i < m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		values[x] = merge(values[2*x+1],values[2*x+2]);
	}
	
	void set(int i , int v){
		set(i,v,0,0,size);
	}
	
	item calc(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return NEUTRAL;
		if(lx >= l && rx <= r) return values[x];
		int m = (lx+rx)/2;
		item s1 = calc(l,r,2*x+1,lx,m);
		item s2 = calc(l,r,2*x+2,m,rx);
		return merge(s1,s2);
	}
	
	item calc(int l , int r){
		return calc(l,r,0,0,size);
	}
	
	item find(item k , item x , item lx , item rx){
		if(rx-lx==1){
			return lx;
		}
		item m = (lx + rx)/2;
		item sl = values[2*x+1];
		if(k < sl){
			return find(k , 2*x+1, lx , m);
		}
		else{
			return find(k-sl,2*x+2, m , rx);
		}
	
	}
	item find(item k){
		return find(k,0,0,size);
	}
	
};
 
void test_case() {
	segtree st;
	int n;
	cin >> n;
	st.init(n);
	vector<int> a(n,1);
	st.build(a);
	vector<int> p(n);
	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}
	int total = n-1;
	for(int i = n-1 ; i >= 0 ; i--){
		int k = total-p[i];
		a[i] = st.find(k);
		st.set(a[i],0);
		total--;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<a[i]+1<<" ";
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

// dont take stress
// remember the i , j index in double loop
// typing slow but dont make mistake while thinking and typing

