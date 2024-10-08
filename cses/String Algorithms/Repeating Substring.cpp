#include <bits/stdc++.h>
using namespace std;

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

void test(){
    // take input string pass in suffix array which will return pair of vectors of suffix array and counting array
    // always try to make a single suffix array
    // pass suffix array and counting array and string to longest commom prefix fuction of lcp array 
	// erase first of suffix array
	// erase last of string
	string s;
	cin >> s;
	pair<vector<int>,vector<int>> l = suffix_array(s);
	vector<int> p = l.first;
	vector<int> c = l.second;
	vector<int> lcp = longest_common_prefix(p,c,s);
	string ans = "";
	int n = s.size();
	// for(auto x : lcp)
	// 	cout<<x<<" ";
	for(int i = 1 ; i < n ; i++){
		if(lcp[i] > (int)ans.size()){
			ans = s.substr(p[i],lcp[i]);
		}
	}
	if(ans == ""){
		cout<<"-1\n";
		return;
	}
	cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    int T = 1;
    while(T--){
        test();
    }
    return 0;
}
