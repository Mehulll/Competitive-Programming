// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 1e5 + 5;
const int INF = -1e17;

struct calc{
    int sum = 0;
    int type = 0;
};

struct my_node{
    calc k;
    my_node(){}
    my_node(calc val){
        k = val;
    }
    void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
        k.sum = l.k.sum + r.k.sum;
    }
};


struct my_update{
    calc k;
    my_update(){}
    my_update(calc val){
        k.sum = val.sum; // 5
        k.type = val.type;
    }
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
        if(other.k.type == 1){
            k.sum = other.k.sum;
            k.type = 1;
        }
        else{
            k.sum += other.k.sum;
        }
    }
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
        if(k.type == 1){
            x.k.sum = (tr - tl + 1) * k.sum;
        }
        else{
            x.k.sum += (tr - tl + 1) * k.sum;
        }
    }
};

template<typename node,typename update>
struct segtree{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
    
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(!lazy[v]) return;
        int32_t tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
    
    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
    
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
    
    node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
    
    // rupd = range update
    void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
    
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }
    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

int cases  = 0;
struct Solver{
    void solve(){
        int n ; cin >> n;
        segtree<my_node,my_update> s(n);
        int m = 0;
        cin >> m;
        while(m--){
            int type;
            cin >> type;
            if(type == 1){
                int l , r , v;
                cin >> l >> r >> v;
                r--;
                calc p;
                p.sum = v;
                p.type = 1;
                s.rupd(l,r,p);
            }
            else if(type == 2){
                int l , r , v;
                cin >> l >> r >> v;
                r--;
                calc p;
                p.sum = v;
                p.type = 2;
                s.rupd(l,r,p);
            }
            else{
                int l , r;
                cin >> l >> r;
                r--;
                cout<<s.query(l,r).k.sum<<"\n";
            }
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
     int ts = 1;
    rrep(ti,ts) {
        cases++;
        Solver solver;
        solver.solve();
    }
    return 0;
}

// 0 0 0 0 0
// 3 3 3 0 0
// 3 3 5 2 0
// 3 4 6 3 1
// 2 2 6 3 1
// 
