#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int arr[MAXN][MAXN];
int n;
int dp[MAXN];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= i; ++ j){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++ i){
		dp[i] = arr[n][i];
	}
	
	for(int i = n - 1; i >= 1; -- i){
		for(int j = 1; j <= i; ++ j){
			dp[j] = arr[i][j] + max(dp[j], dp[j + 1]); 
		}
	}
	cout << dp[1];
	
	return 0;
} 
