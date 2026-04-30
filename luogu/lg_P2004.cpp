#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int arr[MAXN][MAXN];
int pre[MAXN][MAXN];
int n, m, c;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m >> c;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= m; ++ j){
			cin >> arr[i][j];
			pre[i][j] = arr[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
		}
	}
	int X, Y;
	int max_sum = -1e9;
	for(int i = 1; i + c - 1 <= n; ++ i){
		for(int j = 1; j + c - 1 <= m; ++ j){
			int current_sum = pre[i + c - 1][j + c - 1] - pre[i + c - 1][j - 1] - pre[i - 1][j + c - 1] + pre[i - 1][j - 1];
			if(current_sum > max_sum){
				max_sum = current_sum; 
				X = i;
				Y = j;
			}
		}
	}
	cout << X << " " << Y << endl;
	return 0;
} 
