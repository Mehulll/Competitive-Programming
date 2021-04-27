#include <bits/stdc++.h>
using namespace std;
 
#define NMAX 1000006
 
vector<int> calc_z(string& s){
    int n = s.size();
	vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if (i < r)
        {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> prefix_function(string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
void test(){
	string s;
    cin >> s;
    vector<int> z = calc_z(s);
    int n = s.size();
    vector<int> p = prefix_function(s);
    for(int i = 0 ; i < n ; i++)
    	cout<<z[i]<<" ";
    cout<<"\n";
    for(auto x : p)
    	cout<<x<<" ";
}
 
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    int T = 1;
    // cin >> T;
    while(T--){
        test();
    }
    return 0;
}
