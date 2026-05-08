#include<bits/stdc++.h>
using namespace std;

const int MAXM = 10005;
const int MAXT = 1e7 + 5;

int w[MAXM], v[MAXM];
long long dp[MAXT];
int t, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> t >> m;
	for(int i = 1; i <= m; ++ i){
		cin >> w[i] >> v[i];
	}
	
	for(int i = 1; i <= m; ++ i){
		for(int j = w[i]; j <= t; ++ j){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[t] << '\n';
	
	return 0;
} 
