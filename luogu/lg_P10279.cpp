//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 3e5 + 10;
//const int INF = 1e9;
//
//long long n, a, b, c;
//long long s[MAXN];
//long long pre[MAXN];
//long long B[MAXN];
//vector<long long> vals;
//int tr[MAXN];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
//	
//	cin >> n >> a >> b >> c;
//	for(int i = 1; i <= n; ++ i){
//		cin >> s[i];
//		pre[i] = s[i] + pre[i - 1];
////		cout << pre[i] << ' '; pre[r] - pre[l - 1]
//	}
//	
//	
//	
//	return 0;
//} 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300010;
ll n, a, b, c;
ll sum[N]; 
ll f[N];   

int main() {
    ios::sync_with_stdio(0); 
	cin.tie(0), cout.tie(0);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
        ll now;
        cin >> now;
        sum[i] = sum[i-1] + now; 
    }

    f[0] = sum[0] - a * c * 1; 

    for (int i = 1; i <= n; i++) {
        ll current_pot = sum[i] - a * c * (i + 1); 
        f[i] = min(f[i-1], current_pot);          
    }

    ll ans = 0; 

    for (int R = 1; R <= n; R++) {
        ll x = sum[R] - a * b * R; 

        int l = -1, r = R; 
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (f[mid] < x) {
                r = mid; 
            } else {
                l = mid; 
            }
        }

        if (r < R) { 
            ans = max(ans, (ll)(R - r));
        }
    }

    cout << ans << "\n";
    return 0;
}
