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


void counting_sort(vector<int> &p , vector<int> &c){
    int n = p.size();
    
    vector<int> cnt(n);
    for(auto x : c){
        cnt[x]++;
    }
    vector<int> pnew(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1 ; i < n ; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        int i = c[x];
        pnew[pos[i]] = x;
        pos[i]++;
    }
    p = pnew;
    
}

pair<int,int> look(string& t , vector<int>& p , string& s){
    int n = p.size() , k = t.size();
    int l = 0 , r = n-1;
    int x = 0 , y = 0;
    while(l <= r){
        int mid = (l+r)/2;
        string pre = s.substr(p[mid],k);
        if(pre <= t){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    x = l;
    l = 0 , r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        string pre = s.substr(p[mid],k);
        if(pre < t){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    y = l;
    if(x == y)
    	return {-1,-1};
    return {x,y};
}

void test(){
    string s;
    cin >> s;
    s+='$';
    int n = s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i = 0 ; i < n ; i++)
            a[i] = {s[i],i};
        sort(a.begin(),a.end());
        
        for(int i = 0 ; i < n ; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1 ; i < n ; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    int k = 0;
    while((1 << k) < n){
        for(int i = 0 ; i < n ; i++){
            p[i] = (p[i] - (1 << k)+n)%n;
        }
        counting_sort(p,c);
        vector<int> cnew(n);
        cnew[p[0]] = 0;
        for(int i = 1 ; i < n ; i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+(1 << k))%n]};
            pair<int,int> now = {c[p[i]],c[(p[i]+(1 << k))%n]};
            if(now == prev){
                cnew[p[i]] = cnew[p[i-1]];
            }
            else{
                cnew[p[i]] = cnew[p[i-1]] + 1;
            }
        }
        c = cnew;
        k++;
    }
    p.erase(p.begin());
    s.pop_back();
    segtree st;
    n = s.size();
    st.init(n);
    st.build(p);
    // cout<<st.calc(0,1)<<" ";
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        pair<int,int> ans = look(t,p,s);
        if(ans.first == -1 && ans.second == -1){
        	cout<<"-1\n";
        }
        else{
        	// cout<<ans.first<<" "<<ans.second<<" ";
        	cout<<st.calc(ans.second,ans.first)+1<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    int T = 1;
    // cin >> T;
    while(T--){
        test();
    }
    return 0;
}
