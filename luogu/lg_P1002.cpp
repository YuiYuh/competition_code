#include<bits/stdc++.h>
using namespace std;

const int MAXN = 25;
bool ma[MAXN][MAXN];
long long dp[MAXN][MAXN];
int en, em, n, m;

int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> en >> em >> n >> m;
	for(int i = 0; i < 9; ++ i){
		int x = n + dx[i];
        int y = m + dy[i];

        if(x >= 0 && x <= en && y >= 0 && y <= em){
            ma[x][y] = true;
        }
	}
	
	if(ma[0][0]){
		cout << 0 << '\n';
		return 0;
	}
	
	dp[0][0] = 1;
	for(int i = 0; i <= en; ++ i){
		for(int j = 0; j <= em; ++ j){
			if(i == 0 && j == 0) continue;
			
			if(ma[i][j]){
				dp[i][j] = 0;
			}else{
				if(i > 0) dp[i][j] += dp[i - 1][j];
				if(j > 0) dp[i][j] += dp[i][j - 1];
			}
		}
	}
		
	cout << dp[en][em] << '\n';
	
	return 0;
} 
