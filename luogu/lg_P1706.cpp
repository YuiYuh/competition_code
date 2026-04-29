#include<bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 10;
int arr[MAXN];
bool vis[MAXN];

void dfs(int x){
	if(x > n){
		for(int i = 1; i <= n; ++ i){
			cout << setw(5) << arr[i];
		}
		cout << '\n';
		return ;
	}
	
	for(int i = 1; i <= n; ++ i){
		if(!vis[i]){
			vis[i] = true;
			arr[x] = i;
			dfs(x + 1);
			vis[i] = false;
		}
	}
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n;
	
	dfs(1);
	
	
	return 0;
} 



//void dfs(int x){
//	if(x > n){
//		for(int i = 1; i <= n; ++ i){
//			cout << setw(5) << arr[i];
//		}
//		cout << '\n';
//		return ;
//	}
//	
//	for(int i = 1; i <= n; ++ i){
//		if(!vis[i]){
//			vis[i] = true;
//			arr[x] = i;
//			dfs(x + 1);
//			vis[i] = false;
//		}
//	}
//	
//} 









