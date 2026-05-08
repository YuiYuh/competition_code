#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

typedef pair<int, int> PII;
int mp[MAXN][MAXN];
int mem[MAXN][MAXN];

int r, c;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y){// 返回从当前点下滑的最大长度 
	if(mem[x][y] != 0){
		return mem[x][y];
	}
	mem[x][y] = 1;
	for(int i = 0; i < 4; ++ i){
		int nx = x + dx[i],
		    ny = y + dy[i];
		if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
		if(mp[nx][ny] < mp[x][y]){
			mem[x][y] = max(mem[x][y], dfs(nx, ny) + 1);
		}
	}
	return mem[x][y];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for(int i = 1; i <= r; ++ i){
		for(int j = 1; j <= c; ++ j){
			cin >> mp[i][j];
		}
	}
	int ans = 0;
	
	for(int i = 1; i <= r; ++ i){
		for(int j = 1; j <= c; ++ j){
			ans = max(ans, dfs(i, j));
		}
	}
	
	cout << ans << '\n';
	return 0;
}
