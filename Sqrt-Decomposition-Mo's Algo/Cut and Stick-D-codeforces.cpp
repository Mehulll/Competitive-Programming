#include <bits/stdc++.h>
using namespace std;

int BLK = 555;

struct query{
	int L , R , i;
};

const int nax = 1e6+5;

query Q[nax];
int ar[nax] , ans[nax] , fre[nax] , cnt = 0 , counter[nax];

bool comp(query a , query b){
	if(a.L/BLK != b.L/BLK)
		return a.L/BLK < b.L/BLK;
	return a.R < b.R;
}

void add(int pos){
	int val = ar[pos];
	int c = fre[val];
	counter[c]--;
	fre[val]++;
	counter[fre[val]]++;
	cnt = max(cnt,fre[val]);
}

void remove(int pos){
	int val = ar[pos];
	int c = fre[val];
	counter[c]--;
	fre[val]--;
	counter[fre[val]]++;
	while(counter[cnt] == 0)
		cnt--;
}

void test_case(){
	int n , q;
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}
	for(int i = 0 ; i < q ; i++){
		cin >> Q[i].L >> Q[i].R;
		Q[i].i = i;
		Q[i].L-- , Q[i].R--;
	}
	sort(Q,Q+q,comp);

	// why ML = 0 , and MR = -1?
	int ML = 0 , MR = -1;
	for(int i = 0 ; i < q ; i++){
		int L = Q[i].L;
		int R = Q[i].R;
		while(ML > L)
			ML-- , add(ML);
		while(MR < R)
			MR++ , add(MR);
		while(ML < L)
			remove(ML) , ML++;
		while(MR > R)
			remove(MR) , MR--;
		ans[Q[i].i] = max(2*cnt-(R-L+1),1);
	}
	for(int i = 0 ; i < q ; i++)
		cout<<ans[i]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(10);
	int T = 1;
	// cin >> T;
	while(T--){
		test_case();
	}
}

// MO's algorithm

