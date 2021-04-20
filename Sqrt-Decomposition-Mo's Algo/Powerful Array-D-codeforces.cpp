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
//#define ar array 
#define int ll
const int BLK = 500 , nax = 1e6+5;
int n , q , ar[nax] , F[nax] , freq[nax] , cnt = 0 , power = 0;

struct query{
	int L , R , c;
};

bool comp(query a , query b){
	if(a.L/BLK != b.L/BLK)
		return a.L/BLK < b.L/BLK;
	else
		return a.R < b.R;
	}
	
void add(int pos){
	cnt = freq[ar[pos]];
	freq[ar[pos]]++;
	power-=(cnt*cnt)*ar[pos],cnt++;
	power+=(cnt*cnt)*ar[pos];
}

void remove(int pos){
	cnt = freq[ar[pos]];
	freq[ar[pos]]--;
	power-=(cnt*cnt)*ar[pos],cnt--;
	power+=(cnt*cnt)*ar[pos];
}
	
void test_case() {
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++)
		cin >> ar[i];
	vector<query> Q;
	vector<int> ans(q);
	int m = 0;
	while(q--){
		query l;
		cin >> l.L >> l.R;
		l.L-- , l.R--;
		l.c = m;
		Q.push_back(l);
		m++;
	}
	sort(Q.begin(),Q.end(),&comp);
	int ML = 0 , MR = -1;
	for(int i = 0 ; i < (int)Q.size() ; i++){
		int l = Q[i].L;
		int r = Q[i].R;
		int idx = Q[i].c;
		while(MR < r)
			MR++ , add(MR);
		while(ML > l)
			ML-- ,add(ML);
		while(MR > r)
			remove(MR),MR--;
		while(ML < l)
			remove(ML),ML++;
		ans[idx] = power;
	}
	for(auto &x : ans)
		cout<<x<<"\n";
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	//~ cin >> T;
	while(T--){
		test_case();
	}
}

// hilbert curve ordering
