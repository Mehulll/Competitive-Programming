#include <bits/stdc++.h>
#define f(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
#define int long long
const int RIGHT = 262144;
const int SIZE = 524288;
int N, Q, K[SIZE], D[SIZE], LK[SIZE], LD[SIZE], S[SIZE];

int query(int l, int r, int n = 1, int a = 1, int b = RIGHT)
{
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return S[n];

    if(LK[n] != 0 || LD[n] != 0)
    {
        int sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    int mid = (a+b) / 2;
    return query(l,r,2*n,a,mid) + query(l,r,2*n+1,mid+1,b);
}

void update(int l, int r, int k, int d, int n = 1, int a = 1, int b = RIGHT)
{
    if(a >= l && b <= r)
    {
        K[n] += k, D[n] += d;
        LK[n] += k, LD[n] += d;
        int sz = (b-a+1);
        S[n] += k*sz + d*sz*(sz-1) / 2;
        return;
    }

    if(LK[n] != 0 || LD[n] != 0)
    {
        int sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    int mid = (a+b) / 2;
    if(l <= mid) update(l,min(mid,r),k,d,2*n,a,mid);
    if(r > mid) update(max(mid+1,l),r,k + d*max(mid-l+1,0LL),d,2*n+1,mid+1,b);

    S[n] = S[2*n] + S[2*n+1];
}

int32_t main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N >> Q;
    while(Q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l,r,k,d;
            cin >> l >> r >> k >> d;
            // scanf("%d %d %d %d", &l, &r, &k, &d);
            // l-- , r--;
            update(l,r,k,d);
        }
        else
        {
            int l;
            // scanf("%d", &l);
            cin >> l;
            // l--;
            cout<<query(l,l)<<"\n";
        }
    }
}
