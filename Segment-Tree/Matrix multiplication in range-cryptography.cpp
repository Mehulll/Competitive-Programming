// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 1e5 + 5;
const int INF = -1e12;
int mod;
struct calc{
    int a = 1 , b = 0 , c = 0 , d = 1;
};

struct my_node{
    calc c;
    my_node(){}
    my_node(calc val){
        c.a = (val.a)%mod;
        c.b = (val.b)%mod;
        c.c = (val.c)%mod;
        c.d = (val.d)%mod;
        // cout<<c.a<<" "<<c.b<<" "<<c.c<<" "<<c.d<<"\n";
    }
    void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
        c.a = ((l.c.a*r.c.a)%mod + (l.c.b*r.c.c)%mod)%mod;
        c.b = ((l.c.a*r.c.b)%mod + (l.c.b*r.c.d)%mod)%mod;
        c.c = ((l.c.c*r.c.a)%mod + (l.c.d*r.c.c)%mod)%mod;
        c.d = ((l.c.c*r.c.b)%mod + (l.c.d*r.c.d)%mod)%mod;
    }
};


struct my_update{
    int v = 0; // 4
    my_update(){}
    my_update(int val){
        v = val; // 5
    }
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
    }
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
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
        int n , m ; cin >> mod >> n >> m;
        segtree<my_node,my_update> s(n);
        vector<calc> a(n);
        rep(i,n){
         cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        }
        s.build(a);
        while(m--){
           int left , right;
           cin >> left>> right;
           left-- , right-- ;
           // cout<<left<<" "<<right<<" ";
           calc e = s.query(left,right).c;
           cout<<e.a<<" "<<e.b<<"\n";
           cout<<e.c<<" "<<e.d<<"\n\n";
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

