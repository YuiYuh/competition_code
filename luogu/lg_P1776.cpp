#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 4e4 + 5;

int n, m;
long long dp[MAXM];
int v[MAXN];
int w[MAXN];
int cnt;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		int value, weight, amount;
		cin >> value >> weight >> amount;
		
		int k = 1;
		while(amount >= k){
			cnt++;
			v[cnt] = k * value;
			w[cnt] = k * weight;
			
			amount -= k;
			k *= 2;
		}
		
		if(amount > 0){
			cnt++;
		 	v[cnt] = amount * value;
            w[cnt] = amount * weight;	
		}
	}
	
	for (int i = 1; i <= cnt; ++i) {
        for (int j = m; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[m] << '\n';
	
	
	
	
	return 0;
}
