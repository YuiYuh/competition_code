#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
typedef pair<int, int> PII;
char mp[MAXN][MAXN];
int dist[MAXN][MAXN];
int hh = 0, tt = -1;
PII q[MAXN * MAXN];
int sx, sy, ex, ey, n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(){
	
	q[++tt] = {sx, sy};
	dist[sx][sy] = 0;
	
	
	while(hh <= tt){
		PII curr = q[hh++];
		
		for(int i = 0; i < 4; ++ i){
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			
			if(nx <= 0 || nx > n || ny <= 0 || ny > n || dist[nx][ny] != -1) continue;
			if(mp[nx][ny] == mp[curr.first][curr.second]) continue;
			
			if(mp[nx][ny] == 'B'){
				return dist[curr.first][curr.second] + 1;
			}
			dist[nx][ny] = dist[curr.first][curr.second] + 1;
			q[++tt] = {nx, ny};
		}
	}
	return -1;
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> mp[i][j];
			if(mp[i][j] == 'A'){
				sx = i; sy = j;
			}
			if(mp[i][j] == 'B'){
				ex = i; ey = j;
			}
		}
	}
	cout << bfs() << '\n';
	
	return 0;
} 
