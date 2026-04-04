#include<bits/stdc++.h>
using namespace std;

int arr[5][5];
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int ans = 0x3f3f3f3f;

void dfs(int start, int step){
	if(step > ans) return ;
	if(start == 9){
		bool flag = true;
		for(int i = 0; i < 3; ++ i){
			for(int j = 0; j < 3; ++ j){
			if(arr[i][j] == 0)
			flag = false;
			}
		}
		if(flag) ans = min(ans,step);
		return ; 
	}
	
	//bu选的话
	dfs(start + 1, step);
	
	//选的话 
	int r = start / 3;
	int c = start % 3;
	
	for(int i = 0; i < 5; ++ i){
		int nx = r + dx[i];
    	int ny = c + dy[i];
    	if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
        	arr[nx][ny] ^= 1; 
    	}
	}
	dfs(start + 1, step + 1);
	//恢复现场 
	for(int i = 0; i < 5; ++ i){
		int nx = r + dx[i];
    	int ny = c + dy[i];
    	if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
        	arr[nx][ny] ^= 1; 
    	}
	}
	
}//先全不选 然后从尾巴开始选 跑完所有的逻辑 


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for(int i = 0; i < 3; ++ i){
		for(int j = 0; j < 3; ++ j){
			cin >> arr[i][j];
		}
	}
	
	dfs(0, 0);
	cout << ans << endl;
	
	return 0;
} 
