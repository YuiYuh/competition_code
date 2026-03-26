#include<bits/stdc++.h>
using namespace std;

int n;
char a[110][110];
bool res[110][110];
string target = "yizhong";
 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0 ,1};

bool dfs(int r, int c, int k, int step){
	if(step == 7) return true;
	
	if(r < 1 || r > n || c < 1 || c > n || a[r][c] != target[step]) return false;
	
	if(dfs(r + dx[k], c + dy[k], k, step + 1)){
		res[r][c] = true;
		return true;
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(a[i][j] == 'y'){
				for(int k = 0; k < 8; ++k){
					dfs(i, j, k, 0);
				}
			} 
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(res[i][j]){
				cout << a[i][j];
			}else{
				cout << '*';
			}

		}
	cout <<'\n';
	}
	return 0;
}
