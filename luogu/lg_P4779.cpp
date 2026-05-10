#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = INT_MAX;
int n, m, s;

struct Edge{
	int to, weight;
};
struct Node{
	int id, dist;
	bool operator < (const Node& other)const{
		return dist > other.dist;
	}
};

vector<Edge> g[MAXN];
int dis[MAXN];
bool vis[MAXN]; 


void dijkstra(){
	memset(dis, 0x3f, sizeof dis);
	priority_queue<Node> pq;
	
	pq.push({s, 0});
	dis[s] = 0;
	
	while(!pq.empty()){
		auto curr = pq.top();
		pq.pop();
		int u = curr.id;
		if(vis[u]) continue;
		vis[u] = true;
		for(auto& edge : g[u]){
			int v = edge.to;
			int w = edge.weight;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
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
	
	dijkstra();
	
	for(int i = 1; i <= n; ++ i){
		cout << dis[i] << (i == n ? "" : " ");
	}
	
	cout << '\n';
	
	return 0;
} 
