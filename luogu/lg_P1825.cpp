#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;
typedef pair<int, int> PII;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char mp[MAXN][MAXN];
int dist[MAXN][MAXN];
int n, m;
int sx, sy;
vector<PII> v[26]; 


int bfs(){
	queue<PII> q;
	memset(dist, -1, sizeof dist);
	q.push({sx, sy});
	dist[sx][sy] = 0;
	while(!q.empty()){
		PII cur = q.front();
		q.pop();
		
		if(mp[cur.first][cur.second] == '='){
			return dist[cur.first][cur.second];
		}
		
		for(int i = 0; i < 4; ++ i){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx <= 0 || nx > n || ny <= 0 || ny > m){
				continue;
			}
			if(mp[nx][ny] == '#'){
				continue;
			}
			if(mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z'){
				int id = mp[nx][ny] - 'A';
				PII p1 = v[id][0];
				PII p2 = v[id][1];
				if(make_pair(nx, ny) == p1){
        			nx = p2.first;
        			ny = p2.second;
    			}else{
        			nx = p1.first;
       				ny = p1.second;
    			}
			}
		
			if(dist[nx][ny] == -1){
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({nx, ny});
			}
			
		}
		
	}
	
	
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;

	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= m; ++ j){
			cin >> mp[i][j];
			if(mp[i][j] == '@'){
				sx = i, sy = j;
			}
			if(mp[i][j] >= 'A' && mp[i][j] <= 'Z'){
				v[mp[i][j] - 'A'].push_back({i, j});
			}
		}
	}
	
	cout << bfs() << '\n';
	
	return 0;
}
