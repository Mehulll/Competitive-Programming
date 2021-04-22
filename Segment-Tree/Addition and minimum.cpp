// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
#include <bits/stdc++.h>
using namespace std;

struct segtree{
	int size;
	vector<long long> operations;
	vector<long long> mins;
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		operations.assign(2*size,0LL);
		mins.assign(2*size,0LL);
	}

	void op(int l , int r ,int v , int x , int lx , int rx){
		if(lx >= r || l >= rx) return;
		if(lx >= l && rx <= r){
			operations[x]+=v;
			mins[x] += v; 
		 	return;
		}
		int m = (lx+rx)/2;
		op(l,r,v,2*x+1,lx,m);
		op(l,r,v,2*x+2,m,rx);
		mins[x] = std::min(mins[2*x+1],mins[2*x+2]) + operations[x];
		return;
	}

	void op(int l , int r , int v){
		op(l,r,v,0,0,size);
	}

	long long min(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return LLONG_MAX;
		if(lx >= l && rx <= r){
			return mins[x];
		}
		int m = (lx+rx)/2;
		auto m1 = min(l,r,2*x+1,lx,m);
		auto m2 = min(l,r,2*x+2,m,rx);
		// mins[x] = min(mins[2*x+1],mins[2*x+2]);
		return std::min(m1,m2) + operations[x];
	}

	long long min(int l , int r){
		return min(l,r,0,0,size);
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
			cout<<st.min(l,r)<<"\n";
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
