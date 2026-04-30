#include<iostream>
using namespace std;

const int MAXN = 7;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[MAXN][MAXN];
bool ob[MAXN][MAXN];

int n, m, t, ans;
int sx, sy, fx, fy;

void dfs(int x, int y){
    if(x == fx && y == fy){
        ans++;
        return ;
    }
    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1|| ny > m) continue;
        if(vis[nx][ny]) continue;
        if(ob[nx][ny]) continue;

            vis[nx][ny] = true;
            dfs(nx, ny);
            vis[nx][ny] = false;
        

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    while(t--){
        int x, y;
        cin >> x >> y;
        ob[x][y] = true;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);

    cout << ans << endl;

    return 0;
}