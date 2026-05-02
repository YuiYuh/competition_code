#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 405;
typedef pair<int, int> PII;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dist[MAXN][MAXN];
PII q[MAXN * MAXN];
int n, m, x, y;

void bfs(){
    int hh = 0, tt = 0;
    while(hh <= tt){
        PII t = q[hh++];
        for(int i = 0; i < 8; ++ i){
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1){
                dist[nx][ny] = dist[t.first][t.second] + 1;
                q[++tt] = {nx, ny};
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(dist, -1, sizeof dist);

    cin >> n >> m >> x >> y;
    dist[x][y] = 0;
    q[0] = {x, y};

    bfs();

    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cout << dist[i][j] << (j == m ? "" : " ");
        }
        cout << '\n';
    }

    return 0;
}