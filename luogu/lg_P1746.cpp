#include<iostream>
// #include<cstring>
using namespace std;

const int MAXN = 1005;  
typedef pair<int, int> PII;
PII q[MAXN * MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int dist[MAXN][MAXN];
int n;
int a1, b1, a2, b2;

int bfs(){
    memset(vis, -1, sizeof vis);
    memset(dist, -1, sizeof dist);
    vis[a1][b1] = 1;
    vis[a2][b2] = 2;
    dist[a1][b1] = 0;
    dist[a2][b2] = 0;
    q[0] = {a1, b1};
    q[1] = {a2, b2};
    int hh = 0, tt = 1;

    while(hh <= tt){
        PII t = q[hh++];
        for(int i = 0; i < 4; ++ i){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(vis[nx][ny] != -1){
                if(vis[nx][ny] + vis[t.first][t.second] == 3){
                    return dist[t.first][t.second] + 1;
                }
                continue;
            }

            dist[nx][ny] = dist[t.first][t.second] + 1;
            if(vis[nx][ny] != -1){
                vis[nx][ny] = vis[t.first][t.second];
            }
            q[++tt] = {nx, ny};
        }

    }


    return -1;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    cin >> n;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            cin >> mp[i][j];
        }
    }
    cin >> a1 >> b1 >> a2 >> b2;
    cout << bfs() << endl;


    return 0;
}