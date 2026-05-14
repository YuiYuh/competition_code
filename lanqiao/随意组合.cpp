#include<bits/stdc++.h>
using namespace std;

int a1[] = {0, 2, 3, 5, 8, 0};
int a2[] = {0, 1, 4, 6, 7, 0};

bool vis[10];
int arr[10];
const int n = 4;
int ans;

bool check(){
	long long temp1 = 0;
	long long temp2 = 0;
	for(int i = 1; i <= 4; ++ i){
		temp1 += (a1[i] * 10 + a2[arr[i]]) * (a1[i] * 10 + a2[arr[i]]);
	}
	for(int i = 1; i <= 4; ++ i){
		temp2 += (a2[arr[i]] * 10 + a1[i]) * (a2[arr[i]] * 10 + a1[i]);
	}
	return temp1 == temp2;
}



void dfs(int pos){
	if(pos == 5){
		if(check()) ans++;
		return ;
	}
	
	for(int i = 1; i <= n; ++ i){
		if(vis[i]) continue;
		
		arr[pos] = i;
		vis[i] = true;
		dfs(pos + 1);
		vis[i] = false;
	}	
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	dfs(1);
	
	cout << ans << endl;
	
	
	return 0;
}
