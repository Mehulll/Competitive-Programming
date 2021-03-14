#include <bits/stdc++.h>
using namespace std;

int g;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y) {
    int x0 , y0;
    g = gcd(abs(a),abs(b),x0,y0);
    if (c % g) {
        return false;
    }
    x = x0 * c / g;
    y = y0 * c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

void test(){
    int a , b , c , x, y;
    cin >> a >> b >> c;
    find_any_solution(a,b,c,x,y);
    while(x <= 0)
        x+= b/g , y-=a/g;
    while(x-b/g > 0)
        x-=b/g , y+=a/g;
    cout<<x<<" "<<y<<endl;    
}

int main(){
    int q;
    cin >> q;
    while(q--)
        test();
}
