#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
// #define int ll
const int N = 2e5 + 5;
const int INF = 1e9+1;
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
        v = val; // 5
    }
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
      v += other.v;
    }
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
        x.node_val += (tr-tl+1)*v;
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

vector<int> longest_common_prefix(vector<int>& p , vector<int>& c , string& s){
    int n = s.size();
    vector<int> lc(n);
    int k = 0;
    for(int i = 0 ; i < n-1 ; i++){
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k] == s[j+k])
            k++;
        lc[pi] = k;
        k = max(k-1,0);
    }
    return lc;
}

pair<vector<int>,vector<int>> suffix_array(string& s){
    s+='#';
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
    return {p,c};
}

int cases  = 0;
struct Solver{
    void solve(){
      string str;
      cin >> str;
      int n = str.size();
      segtree<my_node,my_update> s(n+1);
      pair<vector<int>,vector<int>> l = suffix_array(str);
      vector<int> p = l.first , c = l.second;
      vector<int> lcp = longest_common_prefix(p,c,str);
      for(int i = 1 ; i <= n ; i++){
          int le = lcp[i]+1 , r = n-p[i];
          s.rupd(le,r,1);
        }
        for(int i = 1 ; i <= n ; i++){
          cout<<s.query(i,i).node_val<<" ";
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
