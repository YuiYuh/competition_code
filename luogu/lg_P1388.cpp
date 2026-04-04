#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sum[20];
ll dp[20][20];
int n, k;
ll arr[20];



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
	} 
	
	for(int i = 1; i <= n; ++ i){
		sum[i] = sum[i - 1] + arr[i];
		dp[i][0] = sum[i];
	}
	
	for(int j = 1; j <= k; ++ j){//几个乘号 
		for(int i = j + 1; i <= n; ++ i){//前几个数 
			for(int L = j; L < i;++ L){//乘号在第几个数后面 
				dp[i][j] = max(dp[i][j], dp[L][j - 1] * (sum[i] - sum[L]));
			}
		}
	}
	
	cout << dp[n][k] << endl;
	return 0;
} 



