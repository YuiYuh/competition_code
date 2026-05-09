#include<bits/stdc++.h>
using namespace std;

const int MAXM = 1e5 + 5;
const int MAXW = 4e4 + 5;

int v[MAXM], w[MAXM];
long long dp[MAXW];
int n, W;
int k = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> W;
	for(int i = 1; i <= n; ++ i){
		int value, weight, num;
		cin >> value >> weight >> num;
		
		int cnt = 1;
		while(num >= cnt){
			v[k] = value * cnt;
			w[k] = weight * cnt;
			
			num -= cnt;
			k++;
			cnt *= 2;
		}
		
		if(num > 0){
			v[k] = value * num;
			w[k] = weight * num;
			k++; 
		}
		
	}
	for(int i = 1; i < k; ++ i){
		for(int j = W; j >= w[i]; -- j){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	
	cout << dp[W] << '\n';
	return 0;
} 
