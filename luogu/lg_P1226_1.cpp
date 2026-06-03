#include<iostream>
using namespace std;

long long a, b, p;

long long qpow(){
    a %= p;
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a % p;
    }
    long long ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return ans % p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> a >> b >> p;
    int d = a;
    int c = b;

    cout << d << "^" << c << " mod " << p << "=" << qpow() << '\n';

    return 0;
}