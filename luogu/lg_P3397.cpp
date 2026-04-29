#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m;
int d[MAXN][MAXN];
//int arr[MAXN][MAXN];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m;
	while(m--){
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		d[a1][b1]++;
		d[a2 + 1][b1]--;
		d[a1][b2 + 1]--;
		d[a2 + 1][b2 + 1]++;
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			cout << d[i][j] << (j == n ? "\n" : " ");
		}
	}
	
	return 0;
}
