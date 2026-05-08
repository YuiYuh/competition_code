#include<bits/stdc++.h>
using namespace std;

const int MAXT = 1005;
const int MAXM = 105;

int w[MAXM], v[MAXM];
int dp[MAXT];//代表在t下能获得的最大价值 

int t, m;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	
	cin >> t >> m;
	
	for(int i = 1; i <= m; ++ i){
		cin >> w[i] >> v[i];
	}
	for(int i = 1; i <= m; ++ i){
		for(int j = t; j >= w[i]; -- j){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	} 
	cout << dp[t] << endl;
	
	return 0;
}
