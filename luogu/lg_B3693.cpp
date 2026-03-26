#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<vector<ull>> s(n + 1,vector<ull> (m + 1, 0));
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ull val;
            cin >> val;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + val;
        }
    }
    
    ull xor_sum = 0;
    while(q--){
    	int u, v, x, y;
    	cin >> u >> v >> x >> y;
    	
    	ull ans = s[x][y] - s[u - 1][y] - s[x][v - 1] + s[u - 1][v - 1];
    	xor_sum ^= ans;
	}
	cout << xor_sum << '\n';
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
    cin >> t;
    while (t--) solve();
	
	
	return 0;
} 
