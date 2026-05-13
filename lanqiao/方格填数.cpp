#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int ans;
int mp[MAXN][MAXN];
bool num[12];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 1, 0, -1, 1, -1, 1, 0};
 
bool check(int x, int y, int m){
	for(int i = 0; i < 8; ++ i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(abs(mp[nx][ny] - m) == 1){
			return false;
		}
	}
	return true;
} 

void dfs(int n){
	if(n == 11){
		ans++;
		return ;
	}
	int x = n / 4 + 1;
	int y = n % 4 + 1;
	
	for(int i = 0; i <= 9; ++ i){
		if(num[i]) continue;
		
		if(check(x, y, i) == false) continue;
		mp[x][y] = i;
		num[i] = true;
		dfs(n + 1);
		num[i] = false;
		mp[x][y] = -100000;
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	for(int i = 0; i <= 6; ++ i){
		for(int j = 0; j <= 6; ++ j){
			mp[i][j] = -100000;
		}
	}
	
	dfs(1);
	
	cout << ans << endl;
	
	
	return 0;
} 
