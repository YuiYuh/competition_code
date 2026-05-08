//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 1005;
//int mp[MAXN][MAXN];
//long long dp[MAXN][MAXN]; 
//int r;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	
//	cin >> r;
//	for(int i = 1; i <= r; ++ i){
//		for(int j = 1; j <= i; ++ j){
//			cin >> mp[i][j];
//		}
//	}
//	long long ans = 0;
//	dp[1][1] = mp[1][1];
//	for(int i = 2; i <= r; ++ i){
//		for(int j = 1; j <= i; ++ j){
//			if(j == 1){
//				dp[i][j] = dp[i - 1][j] + mp[i][j];
//			}else if(j == i){
//				dp[i][j] = dp[i - 1][j - 1] + mp[i][j];
//			}else{
//				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + mp[i][j];
//			}
//			ans = max(ans, dp[i][j]);
//		}
//	}
//	cout << ans << endl;
//	
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int v[MAXN][MAXN];
long long dp[MAXN];
int n;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++ i){//输入金字塔 
		for(int j = 1; j <= i; ++ j){
			cin >> v[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i){
		dp[i] = v[n][i];
	}//初始化dp  
	for(int i = n - 1; i >= 1; -- i){//从底部往上一路推进 
		for(int j = 1; j <= i; ++ j){
			dp[j] = v[i][j] + max(dp[j], dp[j + 1]);//每一个点 只来自于下面或者右下 
		}
	}
	cout << dp[1] << '\n';//最终会聚集到头部 
	
	return 0;
} 
























