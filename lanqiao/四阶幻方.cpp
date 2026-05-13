#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int mp[MAXN][MAXN];
bool vis[20];
int ans;
const int target = 34; 

bool check_row(int x){
//	int col0 = mp[0][0] + mp[0][1] + mp[0][2] + mp[0][3];
//	for(int i = 1; i < 4; ++ i){
//		int temp = 0;
//		for(int j = 0; j < 4; ++ j){
//			temp += mp[i][j];
//		}
//		if(temp != col0) return false;
//	}
//	for(int i = 0; i < 4; ++ i){
//		int temp = 0;
//		for(int j = 0; j < 4; ++ j){
//			temp += mp[j][i];
//		}
//		if(temp != col0) return false;
//	}
//	if(col0 != (mp[0][0] + mp[1][1] + mp[2][2] + mp[3][3])){
//		return false;
//	}
//	if(col0 != (mp[0][3] + mp[1][2] + mp[2][1] + mp[3][0])){
//		return false;
//	}
//	return true;
	int sum = 0;
	for(int j = 0; j < 4; ++ j){
		sum += mp[x][j];
	}
	return sum == target;
}

bool check_col(int x){
	int sum = 0;
	for(int i = 0; i < 4; ++ i){
		sum += mp[i][x];
	}
	return sum == target;
}

bool check_diag(){
	
    int sum1 = mp[0][0] + mp[1][1] + mp[2][2] + mp[3][3];
    int sum2 = mp[0][3] + mp[1][2] + mp[2][1] + mp[3][0];

    return sum1 == target && sum2 == target;
}

void dfs(int n){
	int x = n / 4;
	int y = n % 4;
	if(n == 16){
		if(check_diag()) ans++;
		return ;
	}
	for(int i = 2; i <= 16; ++ i){
		if(vis[i]) continue;
		
		vis[i] = true;
		mp[x][y] = i;
		
		bool ok = true;
		
		if(y == 3 && !check_row(x)) ok = false;
		if(x == 3 && !check_col(y)) ok = false;
		
		if(ok) dfs(n + 1);
		
		vis[i] = false;
		mp[x][y] = 0;
	}
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	mp[0][0] = 1;
	vis[1] = true; 
	dfs(1);
	
	cout << ans << endl; 
	
	
	
	return 0;
} 
