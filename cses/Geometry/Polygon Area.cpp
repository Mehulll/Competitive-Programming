#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> oset;

struct pt{
    long double x , y;
};

typedef long double T;

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}

long double areaPolygon(vector<pt> p) {
    long double area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i+1)%n]); 
    }
    return abs(area) / 2.0;
}

void test_case(){
   int n;
   cin >> n;
   vector<pt> v(n);
   for(int i = 0 ; i < n ; i++){
    cin >> v[i].x >> v[i].y;
   }
   cout<<(int)(2*areaPolygon(v));
}

int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
        while(t--){
            test_case();
        }
        return 0;
}
