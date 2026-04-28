#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
typedef pair<int, int> PII;
int arr[MAXN][MAXN];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int m, n;
int s1, e1, s2, e2;
bool found;
bool vis[MAXN][MAXN];
vector<PII> path;


void dfs(int x, int y){
	if(x == s2 && y == e2){
		found = true;
		//print
		for(int i = 0; i < path.size(); ++ i){
			cout << "(" << path[i].first << "," << path[i].second << ")" << (i == (int)path.size() - 1 ? "" : "->");
		}
		cout << '\n';
		return ;
	}
	
	for(int i = 0; i < 4; ++ i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && arr[nx][ny] == 1){
			if(!vis[nx][ny]){
				vis[nx][ny] = true;
				path.push_back({nx, ny});
				dfs(nx, ny);
				path.pop_back();
				vis[nx][ny] = false;
			}
		}
	}
	
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> m >> n;
	for(int i = 1; i <= m; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> arr[i][j];
		}
	}
	cin >> s1 >> e1 >> s2 >> e2;
	path.push_back({s1, e1});
	vis[s1][e1] = true;
	dfs(s1, e1);
	if(!found) cout << -1 << endl;
	
	return 0;
} 
