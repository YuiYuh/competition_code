#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
typedef pair<int, int> PII;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char mp[N][N];
int vis[N][N];
int dist[N][N];
int n, a1, b1, a2, b2;
PII q[N * N];

int bfs(){
    memset(vis, -1, sizeof vis);
    memset(dist, -1, sizeof dist);
    q[0] = {a1, b1};
    q[1] = {a2, b2};
    dist[a1][b1] = 0;
    dist[a2][b2] = 0;
    vis[a1][b1] = 1;
    vis[a2][b2] = 2;

    int hh = 0, tt = 1;

    while(hh <= tt){
        PII t = q[hh++];
        for(int i = 0; i < 4; ++ i){
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && mp[nx][ny] == '0'){
                if(vis[nx][ny] != -1){
                    if(vis[nx][ny] + vis[t.first][t.second] == 3){
                        return dist[nx][ny] + dist[t.first][t.second] + 1;
                    }
                    continue;
                }
            dist[nx][ny] = dist[t.first][t.second] + 1;
            if(vis[nx][ny] == -1){
                vis[nx][ny] = vis[t.first][t.second];
            }

            q[++tt] = {nx, ny};

            } 
        }
    }
    return -1;
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
    cin >> a1 >> b1 >> a2 >> b2;

    cout << bfs() << endl;

    return 0;
}