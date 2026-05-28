#include<iostream>
using namespace std;

const int MAXN = 1e5 + 10;
int n;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n;
    ll cur = LLONG_MIN;
    ll ans = LLONG_MIN;
    for(int i = 1; i <= n; ++ i){
        ll a = 0;
        cin >> a;
        if(i == 1){
            cur = a;
            ans = a;
        }else{
            cur = max(a, cur + a);
            ans = max(cur, ans);
        }
        

    }
    cout << ans << '\n';
    return 0;
}