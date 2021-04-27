#include <bits/stdc++.h>
using namespace std;
 
#define int long long

void test(){
	int x1 , y1 , x2 , y2 , x3 , y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int dx = x2-x1;
	int dy = y2-y1;
	int position = dx * (y3-y2) - dy * (x3-x2);
	if(position == 0){
		cout<<"TOUCH\n";
	}
	else if(position < 0){
		cout<<"RIGHT\n";
	}
	else{
		cout<<"LEFT\n";
	}
}
 
int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    int T = 1;
    cin >> T;
    while(T--){
        test();
    }
    return 0;
}
