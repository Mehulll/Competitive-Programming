// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
int a[100001];
int b[100001];
bitset<5001>tree1[400001] , tree2[400001];
void build(int node,int i,int j){
    if(i > j)
        return;
    if(i == j){
        tree1[node].set(a[i]);
        tree2[node].set(b[i]);
        return;
    }
    int mid = (i + j) / 2;
    build(2 * node , i , mid);
    build(2 * node + 1 , mid + 1 , j);
    tree1[node] = tree1[2 * node] | tree1[2 * node + 1];
    tree2[node] = tree2[2 * node] | tree2[2 * node + 1];
}

bitset<5001>query1(int node,int i,int j,int l,int r){
    if(i > j || i > r || j < l)
        return 0;
    if(i >= l && j <= r)
        return tree1[node];
    int mid = (i + j) / 2;
    return query1(2 * node , i , mid , l , r) | query1(2 * node + 1 , mid + 1 , j , l , r);
}

bitset<5001>query2(int node,int i,int j,int l,int r){
    if(i > j || i > r || j < l)
        return 0;
    if(i >= l && j <= r)
        return tree2[node];
    int mid = (i + j) / 2;
    return query2(2 * node , i , mid , l , r) | query2(2 * node + 1 , mid + 1 , j , l , r);
}

int main()
    {
        ios_base::sync_with_stdio(0);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        build(1 , 1 , n);
        int q;
        cin >> q;
        while(q--){
            int a , b , c , d;
            cin >> a >> b >> c >> d;
            cout << (query1(1 , 1 , n , a , b) | query2(1 , 1 , n , c , d)).count() << endl;
        }
    }
