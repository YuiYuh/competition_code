//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 35;
//int arr[MAXN][MAXN];
//bool vis[MAXN][MAXN];
//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//int n;
//
//void dfs(int x, int y){
//	vis[x][y] = true; 
//
//	for(int i = 0; i < 4; ++i){
//		int new_x = x + dx[i];
//		int new_y = y + dy[i];
//		
//		if(new_x >= 0 && new_x <= n + 1 && new_y >= 0 && new_y <= n + 1){
//			if(arr[new_x][new_y] == 0 && !vis[new_x][new_y]){
//				dfs(new_x, new_y);
//			}
//		}
//	}
//}
//
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	cin >> n;
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= n; ++j){
//			cin >> arr[i][j];
//		}
//	}
//	dfs(0, 0);
//	for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            if (arr[i][j] == 1) {
//                cout << 1 << " ";
//            } else {
//                if (!vis[i][j]) cout << 2 << " ";
//                else cout << 0 << " ";
//            }
//        }
//        cout << "\n";
//    }
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 35;
typedef pair<int,int> PII;
int n;
int arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
	
void bfs(int x,int y){
	queue<PII> q;
	
	q.push({x, y});
	vis[x][y] = true;
	
	while(!q.empty()){
		PII curr = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
		
			if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= n + 1){
				if(arr[nx][ny] == 0 && !vis[nx][ny]){
					vis[nx][ny] = true;
					q.push({nx, ny});
				}	
			} 
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
	bfs(0,0);
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1) cout << 1 << " ";
            else if (vis[i][j]) cout << 0 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
	return 0;
} 

