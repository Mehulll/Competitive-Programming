#include <bits/stdc++.h>
using namespace std;

struct segtree{
	int size;
	vector<int> visited;
	void init(int n){
		size = 1;
		while(size < n)
			size*=2;
		visited.assign(2*size,0LL);
	}
	
	void set(int i , int v , int x , int lx , int rx){
		if(rx-lx==1){
			visited[x] = v;
			return;
		}
		int m = (rx+lx)/2;
		if(i < m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		visited[x] = visited[2*x+1]+visited[2*x+2];
	}
	
	void set(int i , int v){
		set(i,v,0,0,size);
	}
	
	int sum(int l , int r , int x , int lx , int rx){
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return visited[x];
		int m = (lx+rx)/2;
		int s1 = sum(l,r,2*x+1,lx,m);
		int s2 = sum(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	
	int sum(int l , int r){
		return sum(l,r,0,0,size);
	}
};


int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	segtree st;
	st.init(n+1);
	vector<int> a(n+1);
	a[0] = 0;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 0 ; i <= n ; i++){
		if(i)
			cout<<st.sum(a[i],n+1)<<" ";
		st.set(a[i],1);
	}
	return 0;
}
