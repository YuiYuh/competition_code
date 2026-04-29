#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int arr[MAXN];
long long pre[MAXN];
int n, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	cin >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		cout << pre[y] - pre[x - 1] << endl;
	}
	
	
	
	
	
	
	return 0;
} 
