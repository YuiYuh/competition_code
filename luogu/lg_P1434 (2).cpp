#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
typedef pair<int, int> PII;
int mem[MAXN][MAXN];
int arr[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

int dfs(int x, int y){
	if(mem[x][y] != 0) return mem[x][y];
	
	int max_len = 1;
	
	for(int i = 0; i < 4; ++ i){
		for(int j = 0; j < 4; ++ j){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
				if(arr[nx][ny] < arr[x][y]){
					max_len = max(max_len, dfs(nx, ny) + 1);
				}
			}
		}	
	}
	
	
	return mem[x][y] = max_len;
	
}





int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= m; ++ j){
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= m; ++ j){
			ans = max(ans, dfs(i, j));
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
