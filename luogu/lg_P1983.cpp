#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m;
vector<int> g[MAXN];
int indeg[MAXN];
int dp[MAXN];
bool edge[MAXN][MAXN];
bool stop_station[MAXN];
int a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i){
		int s; 
		cin >> s;
		memset(stop_station, false, sizeof stop_station);
		for(int j = 1; j <= s; ++ j){
			cin >> a[j];
			stop_station[a[j]] = true;
		}
		
		int l = a[1];
		int r = a[s];
		
		for(int x = l; x <= r; ++ x){
			if(!stop_station[x]){
				for(int j = 1; j <= s; ++ j){
					int u = x;
					int v = a[j];
					if(!edge[u][v]){
						edge[u][v] = true;
						g[u].push_back(v);
						indeg[v]++;
					}
				}
			}
		}
	
	}
	queue<int> q;
	for(int i = 1; i <= n; ++ i){
		if(indeg[i] == 0){
			q.push(i);
			dp[i] = 1;
		}
	}
	int ans = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans = max(ans, dp[u]);
		for(int v : g[u]){
			dp[v] = max(dp[v], dp[u] + 1);
			indeg[v]--;
			if(indeg[v] == 0){
				q.push(v);
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}
