#include<iostream>
using namespace std;

const int MAXN = 105;
char mp[MAXN][MAXN];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};//左上 上 右上 左 右 左下 下 右下
int dy[] = {-1, 0, 1, -1, 1, 1, 0, -1};
int n, m, cnt;

void dfs(int x, int y){
    mp[x][y] = '.';
    
    for(int i = 0; i < 8; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 'W'){
            dfs(nx, ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(mp[i][j] == 'W'){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}