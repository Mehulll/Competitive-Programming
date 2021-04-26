// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 1e5 + 5;
const int INF = 1e12;
int mod;
const int na = 50;

struct calc{
    int node_val = 0;
    int a[na] = {0};
};

int index;
vector<int> value;
int current;

struct my_node{
    calc k;
    my_node(){}
    my_node(calc val){
        k.a[val.node_val]++;
        k.node_val = 0;
    }
    void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
        k.node_val = l.k.node_val + r.k.node_val;
        for(int i = 1 ; i <= 40 ; i++){
            k.a[i] = r.k.a[i] + l.k.a[i];
            if(r.k.a[i]){
                int x = 0;
                for(int j = i+1 ; j <= 40 ; j++){
                    x += l.k.a[j];
                }
                k.node_val += x*r.k.a[i];
            }
        }
    } 
};


struct my_update{
    calc v;
    my_update(){}
    my_update(calc val){
        v.node_val = 0;
        v.a[val.node_val]++;
    }
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
        // this is for range updates
    }
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
         x.k.a[value[index]]--;
         x.k.a[current]++;
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
        int n , m ; cin >> n >> m;
        segtree<my_node,my_update> s(n);
        vector<calc> a(n);
        value.resize(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i].node_val;
            value[i] = a[i].node_val;
        }
        s.build(a);
        while(m--){
            int type;
            cin >> type;
            if(type == 2){
                int i , h;
                cin >> i >> h;
                i--; 
                index = i;
                current = h;
                calc p;
                p.node_val = h;
                s.rupd(i,i,p);
                value[i] = h;
            }
            else{
                int l , r;
                cin >> l >> r;
                l-- , r--;
                cout<<s.query(l,r).k.node_val<<"\n";
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
    // cin >> ts;
    rrep(ti,ts) {
        cases++;
        Solver solver;
        solver.solve();
    }
    return 0;
}


// 3 4 5 8 4
