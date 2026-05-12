#include<bits/stdc++.h>
using namespace std;

const int MOD = 80112002;
int n, m;
const int MAXN = 5005;
vector<int> g[MAXN];
int indeg[MAXN], outdeg[MAXN];
int dp[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; ++ i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		indeg[v]++;
		outdeg[u]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; ++ i){
		if(indeg[i] == 0){
			q.push(i);
			dp[i] = 1;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : g[u]){
			dp[v] = (dp[v] + dp[u]) % MOD;
			indeg[v]--;
			if(indeg[v] == 0){
				q.push(v);
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++ i){
		if(outdeg[i] == 0){
			ans = (ans + dp[i]) % MOD;
		}
	}
	cout << ans << endl; 
	return 0;
} 
