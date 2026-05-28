#include<iostream>
using namespace std;

const int MAXN = 1005;
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
//bool is_alive[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;
bool has_core;

void dfs(int x, int y){
    vis[x][y] = true;
    bool is_core = true;
    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 如果四周有任何一个地方超出了地图边界，或者它是海洋 '.'，说明当前格子会被淹没
        if (nx < 1 || nx > n || ny < 1 || ny > n || mp[nx][ny] == '.') {
            is_core = false;
        }
    }
    if(is_core){
        has_core = true;
    }

    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if(vis[nx][ny] || mp[nx][ny] == '.') continue;
        dfs(nx, ny);
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
    int flooded = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(mp[i][j] == '#' && !vis[i][j]){
                has_core = false;
                dfs(i, j);
                if(!has_core){
                    flooded++;
                }
            }
        }
    }
    cout << flooded << '\n';
    return 0;
}