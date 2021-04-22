// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B
#include <bits/stdc++.h>
using namespace std;

struct segtree{
	int size;
	vector<long long> operations;

	long long operation(long long a , long long b){
		return max(a,b);
	}

	void init(int n){
		size = 1;
		while(size < n) size*=2;
		operations.assign(2*size,0LL);
	}

	void op(int l , int r ,int v , int x , int lx , int rx){
		if(lx >= r || l >= rx) return;
		if(lx >= l && rx <= r){
			operations[x] = operation(operations[x] , v); // change here
		 	return;
		}
		int m = (lx+rx)/2;
		op(l,r,v,2*x+1,lx,m);
		op(l,r,v,2*x+2,m,rx);
		return;
	}

	void op(int l , int r , int v){
		op(l,r,v,0,0,size);
	}

	long long get(int i , int x , int lx , int rx){
		if(rx-lx == 1){
			return operations[x];
		}
		int m = (lx+rx)/2;
		long long res;
		if(i < m){
			res = get(i,2*x+1,lx,m);
		}
		else{
			res = get(i,2*x+2,m,rx);
		}
		return operation(res , operations[x]); // change here
	}

	long long get(int i){
		return get(i,0,0,size);
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
			int index;
			cin >> index;
			cout<<st.get(index)<<"\n";
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
