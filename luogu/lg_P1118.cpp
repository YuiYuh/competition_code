#include<bits/stdc++.h>
using namespace std;

int n, target;
int path[15];
int c[15][15]; // 杨辉三角 
bool vis[15];
bool found = false;

void init(){
	c[0][0] = 1;
	for(int i = 1; i <= 12; ++ i){
		c[i][0] = 1;
		for(int j = 1; j <= i; ++ j){
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
} //标准直角杨辉三角 

void dfs(int k, int s){
	if(s > target) return ;
	if(found) return ;
	
	if(k == n){
		if(s == target){
			for (int i = 0; i < n; i++) {
                cout << path[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            found = true;		
		}
		return ;
	}	
	
	for(int i = 1; i <= n; ++ i){
		if(!vis[i]){
			vis[i] = true;
			path[k] = i;
			
			dfs(k + 1, s + i * c[n - 1][k]);
			vis[i] = false;
			if(found) return ;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> target; 
	init();
	dfs(0,0);
	
	return 0;
}
