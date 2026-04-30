#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 505;
int mp[MAXN][MAXN];
int n, m, a, b;
PII q[MAXN * MAXN];
int dist[MAXN][MAXN];
int hh = 0, tt = -1;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(){
	
	while(hh <= tt){
		PII curr = q[hh++];
		for(int i = 0; i < 4; ++ i){
			int nx = curr.first + dx[i], ny = curr.second + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1){
				dist[nx][ny] = dist[curr.first][curr.second] + 1;
				q[++tt] = {nx, ny};	
			}
		}
	}
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	memset(dist, -1, sizeof dist);
	cin >> n >> m >> a >> b;
	while(a--){
		int x, y;
		cin >> x >> y;
		q[++tt] = {x, y};
		dist[x][y] = 0;
	}
	
	bfs();
	
	while(b--){
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] << '\n';
	}
	
	
	return 0;
} 
