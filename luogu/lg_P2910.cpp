#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m;
int path[MAXN];
int d[MAXN][MAXN];



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i){
		cin >> path[i];
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> d[i][j];
		}
	}
	for(int k = 1; k <= n; ++ k){
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= n; ++ j){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 0;

	for(int i = 1; i < m; ++i){
    	ans += d[path[i]][path[i + 1]];
	}
	cout << ans << '\n';
	
	
	return 0;
} 
