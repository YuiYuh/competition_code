#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = INT_MAX;
struct Edge{
	int to, w;
};
int dist[MAXN];
bool in_queue[MAXN];
vector<Edge> g[MAXN];
int n, m, s;

void spfa(){
	for(int i = 1; i <= n; ++ i){
		dist[i] = INF;
	}
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	in_queue[s] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		in_queue[u] = false;
		for(int i = 0; i < g[u].size(); ++ i){
			int v = g[u][i].to;
			int w = g[u][i].w;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				if(!in_queue[v]){
					q.push(v);
					in_queue[v] = true;
				}
			}
		} 
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= m; ++ i){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	spfa();
	for(int i = 1; i <= n; ++ i){
		cout << dist[i] << (i == n ? "" : " ");
	} 

	return 0;
}
