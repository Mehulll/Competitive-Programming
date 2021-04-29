#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 2e5 + 5;
const int INF = -1e12;
const int mod = 1e9+7;

struct my_node{
    int node_val = 0;
    my_node(){}
    my_node(int val){
        node_val = (val)%mod;
    }
    void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
        node_val = (l.node_val + r.node_val)%mod;
    }
};


struct my_update{
    int v = 0; // 4
    my_update(){}
    my_update(int val){
        v = (val)%mod; // 5
    }
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
    }
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
        x.node_val = (v)%mod;
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

ll add(ll x, ll y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}
ll sub(ll x, ll y) {
  x -= y;
  if (x < 0) return x + mod;
  return x;
}
ll mult(ll x, ll y) {
  return (x * y) % mod;
}

int power(int x,int n,int M){   
    if(n < 0)
      return 0;
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

int pw[N] , inv[N];
int base = 31;
void precalc(){
  pw[0] = 1;
  for(int i = 1 ; i < N ; i++)
    pw[i] = mult(pw[i-1],base);
  int pw_inv = power(base,mod-2,mod);
  inv[0] = 1;
  for(int i = 1 ; i < N ; i++)
    inv[i] = mult(inv[i-1],pw_inv);
}

int cases  = 0;
struct Solver{
    void solve(){
        int n, m ; cin >> n >> m;
        segtree<my_node,my_update> s1(n) , s2(n);
        string str;
        cin >> str;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++){
          a[i] = (pw[i]*(str[i]-'a'+1))%mod;
        }
        vector<int> b(n);
        reverse(str.begin(),str.end());
        for(int i = 0 ; i < n ; i++){
          b[i] = (pw[i]*(str[i]-'a'+1))%mod;
        }
        s1.build(a);
        s2.build(b);
        while(m--){
           int type;
           cin >> type;
           if(type == 1){
            int l;
            cin >> l;
            l--;
            char x;
            cin >> x;
            int value1 = (pw[l]*(x-'a'+1))%mod;
            int value2 = (pw[n-l-1]*(x-'a'+1))%mod;
            s1.rupd(l,l,value1);
            s2.rupd(n-l-1,n-l-1,value2);
           }
           else{
            int l , r;
            cin >> l >> r;
            l-- , r--;
            int sum1 = mult(s1.query(l,r).node_val,(l == 0 ? 1 : inv[l]));
            int sum2 = mult(s2.query(n-1-r,n-1-l).node_val,(n-r-1 == 0 ? 1 : inv[n-r-1]));
            // cout<<sum1<<" "<<sum2<<" ";
            if(sum1 == sum2){
              cout<<"YES\n";
            }
            else{
              cout<<"NO\n";
            }
           }
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    precalc();
     int ts = 1;
    rrep(ti,ts) {
        cases++;
        Solver solver;
        solver.solve();
    }
    return 0;
}

// 24 24*31 24*31*31
