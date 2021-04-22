// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

struct segtree{
	int size;
	vector<long long> operations;
	vector<long long> calculate;

	long long NEUTRAL_ELEMENT = 0;

	long long modify_op(long long a , long long b){
		return (a*b)%mod;
	}

	long long calc_op(long long a , long long b){
		return (a+b)%mod;
	}

	void apply_mod_op(long long &a , long long b){
		a = modify_op(a,b);
	}

	void build(int x , int lx , int rx){
		if(rx == lx+1){
			calculate[x] = 1;
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		calculate[x] = calc_op(calculate[2*x+1],calculate[2*x+2]);
	}

	void init(int n){
		size = 1;
		while(size < n) size*=2;
		operations.assign(2*size,1LL);
		calculate.assign(2*size,0LL);
		build(0,0,size);
	}

	void op(int l , int r ,int v , int x , int lx , int rx){
		if(lx >= r || l >= rx) return;
		if(lx >= l && rx <= r){
			apply_mod_op(operations[x],v);
			apply_mod_op(calculate[x],v);
		 	return;
		}
		int m = (lx+rx)/2;
		op(l,r,v,2*x+1,lx,m);
		op(l,r,v,2*x+2,m,rx);
		calculate[x] = calc_op(calculate[2*x+1],calculate[2*x+2]);
		apply_mod_op(calculate[x],operations[x]);
	}

	void op(int l , int r , int v){
		op(l,r,v,0,0,size);
	}

	long long calc(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
		if(lx >= l && rx <= r){
			return calculate[x];
		}
		int m = (lx+rx)/2;
		auto m1 = calc(l,r,2*x+1,lx,m);
		auto m2 = calc(l,r,2*x+2,m,rx);
		// mins[x] = min(mins[2*x+1],mins[2*x+2]);
		auto res = calc_op(m1,m2);
		apply_mod_op(res,operations[x]);
		return res;
	}

	long long calc(int l , int r){
		return calc(l,r,0,0,size);
	}
};

void test(){
	segtree st;
	int n , m;
	cin >> n >> m;
	st.init(n);
	while(m--){
		int type;
		cin >> type;
		if(type == 1){
			int l , r , v;
			cin >> l >> r >> v;
			st.op(l,r,v);
		}
		else{
			int l,r;
			cin >> l >> r;
			cout<<st.calc(l,r)<<"\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	cout<<fixed<<setprecision(10);
	// cin >> T;
	while(T--){
		test();
	}
}
