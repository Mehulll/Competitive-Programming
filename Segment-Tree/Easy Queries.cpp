// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/easy-queries-751f9372/
#include <bits/stdc++.h>
using namespace std;

struct segtree {
	
	int size;
	vector<int> values;
	void init(int n){
		size = 1;
		while(size < n)
			size*=2;
		values.assign(2*size,0LL);
	}
	
	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				values[x] = a[lx];
			}
			return;
		}
		
		int m = (lx + rx)/2;
		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		values[x] = max(values[2*x+1],values[2*x+2]);
	}
	
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	
	void set(int i , int v , int x , int lx , int rx){
		if(rx-lx==1){
			values[x] = v;
			return;
		}
		int m = (rx+lx)/2;
		if(i < m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		values[x] = max(values[2*x+1],values[2*x+2]);
	}
	
	void set(int i , int v){
		set(i,v,0,0,size);
	}
	
	int calc(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return -1;
		if(lx >= l && rx <= r) return values[x];
		int m = (lx+rx)/2;
		int s1 = calc(l,r,2*x+1,lx,m);
		int s2 = calc(l,r,2*x+2,m,rx);
		return max(s1,s2);
	}
	
	long long calc(int l , int r){
		return calc(l,r,0,0,size);
	}
};

struct segtree2{
	
	int size;
	vector<int> values;
	void init(int n){
		size = 1;
		while(size < n)
			size*=2;
		values.assign(2*size,0LL);
	}
	
	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				values[x] = a[lx];
			}
			return;
		}
		
		int m = (lx + rx)/2;
		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		values[x] = min(values[2*x+1],values[2*x+2]);
	}
	
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	
	void set(int i , int v , int x , int lx , int rx){
		if(rx-lx==1){
			values[x] = v;
			return;
		}
		int m = (rx+lx)/2;
		if(i < m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		values[x] = min(values[2*x+1],values[2*x+2]);
	}
	
	void set(int i , int v){
		set(i,v,0,0,size);
	}
	
	int calc(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return INT_MAX;
		if(lx >= l && rx <= r) return values[x];
		int m = (lx+rx)/2;
		int s1 = calc(l,r,2*x+1,lx,m);
		int s2 = calc(l,r,2*x+2,m,rx);
		return min(s1,s2);
	}
	
	long long calc(int l , int r){
		return calc(l,r,0,0,size);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n , m;
	cin >> n >> m;
	
	segtree st;
	segtree2 st2;
	st2.init(n);
	st.init(n);
	vector<int> a(n);
	vector<int> a2(n);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		a2[i] = a[i];
		if(a[i] == 0){
			a[i] = -1;
			a2[i] = INT_MAX;
		}
		else{
			a[i] = i;
			a2[i] = i;
		}
	}
	st.build(a);
	st2.build(a2);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int i;
			cin >> i;
			// i--;
			if(a[i] == -1){
				st.set(i,i);
				a[i] = i;
			}
			if(a2[i] == INT_MAX){
				st2.set(i,i);
				a[i] = i;
			}
		}
		else{
			int l;
			cin >> l;
			int p = st.calc(0,l);
			if(p == -1)
				cout<<p<<" ";
			else
				cout<<p<<" ";
			p = st2.calc(l+1,n);
			if(p == INT_MAX)
				cout<<-1<<"\n";
			else
				cout<<p<<"\n";

		}
	}
	return 0;
}
