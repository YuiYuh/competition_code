#include<bits/stdc++.h>
using namespace std;

const int MAXN = 35;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
typedef pair<int, int> PII;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
PII q[MAXN * MAXN];
int hh = 0, tt = -1;
int n;

void bfs(){
	q[++tt] = {0, 0};
	vis[0][0] = true;
		
	while(hh <= tt){
		PII t = q[hh++];
		for(int i = 0; i < 4; ++ i){
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if(mp[nx][ny] == 0 && !vis[nx][ny] && nx >= 0 && nx <= n + 1&& ny >= 0 && ny <= n + 1){
				vis[nx][ny] = true;
				q[++tt] = {nx, ny};
			}
		}
		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> mp[i][j];
		}
	}
	
	bfs();
	
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			if(mp[i][j] == 1){
				cout << mp[i][j] << (j == n ? "" : " ");
			}else if(mp[i][j] == 0 && vis[i][j]){
				cout << 0 << (j == n ? "" : " ");
			}else{
				cout << 2 << (j == n ? "" : " ");
			}
		}
		cout << '\n';
	}

	
	return 0;
}
