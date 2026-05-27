#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
//0ooooooooooooo0    4042 + 2021

long long qpow(long long a, long long b){
    a = a % MOD;
    long long ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long ans = 0;
    ans = (qpow(2, 4042) + qpow(2, 2021)) % MOD;

    cout << ans << endl;


    return 0;
}