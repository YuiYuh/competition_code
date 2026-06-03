#include<iostream>
using namespace std;

int n;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    long long cur = LLONG_MIN;
    long long ans = LLONG_MIN;
    for(int i = 0; i < n; ++ i){
        long long x;
        cin >> x;
        if(i == 0){
            cur = x;
            ans = x;
        }else{
            cur = max(x + cur, x);
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';

    return 0;
}